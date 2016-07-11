/****************************************************************************
**
** Copyright (C) 2016
**
** This file is generated by the Magus toolkit
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
****************************************************************************/

// Include
#include "material_browser.h"
#include "material_tree.h"

//****************************************************************************/
MaterialTreeDockWidget::MaterialTreeDockWidget(const QString& iconDir, const QString& title, QMainWindow* parent, Qt::WindowFlags flags) :
    QDockWidget (title, parent, flags),
    mParent(parent)
{
    mIconDir = iconDir;
    mEmptyString = "";
    mResourceTreeWidget = new Magus::QtResourceTreeWidget(iconDir);
    mResourceTreeWidget->mActionDuplicateAssetText = QString("Clone material");
    mResourceTreeWidget->mActionDeleteResourceText = QString("Remove from list");
    mResourceTreeWidget->setAddAssetAfterDuplicateAssetSelected(false); // Do not duplicate automatically
    mResourceTreeWidget->setCreateTopLevelGroupContextMenuItemEnabled(false);
    mResourceTreeWidget->setDeleteTopLevelGroupEnabled(false);
    mResourceTreeWidget->setTopLevelGroupItemEditable(false);
    mResourceTreeWidget->setSubLevelGroupItemEditable(true);
    mResourceTreeWidget->setCreateAssetContextMenuItemEnabled(false);
    mResourceTreeWidget->setAssetItemEditable(false);
    mResourceTreeWidget->setDeleteResourceContextMenuItemEnabled(true);
    mResourceTreeWidget->setImportAssetContextMenuItemEnabled(false);
    mResourceTreeWidget->setDuplicateAssetContextMenuItemEnabled(true);

    // Miscellanious settings
    mResourceTreeWidget->addCustomContextMenuItem(ACTION_EDIT);

    // Listen to events.
    // Note, that although the 'create asset' context menu is disabled, the MaterialTreeDockWidget must still handle the 'resourceAdded'
    // signal, because it is also emitted when a subgroup is created in the mResourceTreeWidget; the subgroup must be added to
    // mSourceInfo after creation, to be able to recursively delete any assets resided in subgroups (these assets must also be
    // properly deleted from the MaterialThumbsDockWidget).
    connect(mResourceTreeWidget, SIGNAL(resourceSelected(int)), this, SLOT(handleResourceSelected(int)));
    connect(mResourceTreeWidget, SIGNAL(resourceDoubleClicked(int)), this, SLOT(handleResourceDoubleClicked(int)));
    connect(mResourceTreeWidget, SIGNAL(resourceAdded(int)), this, SLOT(handleResourceAdded(int)));
    connect(mResourceTreeWidget, SIGNAL(resourceDeleted(int)), this, SLOT(handleResourceDeleted(int)));
    connect(mResourceTreeWidget, SIGNAL(resourceMoved(int)), this, SLOT(handleResourceMoved(int)));
    connect(mResourceTreeWidget, SIGNAL(resourceSearched(QString)), this, SLOT(handleResourceSearched(QString)));
    connect(mResourceTreeWidget, SIGNAL(resourceSearchReset()), this, SLOT(handleResourceSearchReset()));
    connect(mResourceTreeWidget, SIGNAL(assetDuplicated(int)), this, SLOT(handleResourceDuplicated(int)));
    connect(mResourceTreeWidget, SIGNAL(customContextMenuItemSelected(QString,int)), this, SLOT(handleCustomContextMenuItemSelected(QString, int)));
    mInnerMain = new QMainWindow();
    mInnerMain->setCentralWidget(mResourceTreeWidget);
    setWidget(mInnerMain);
    QWidget* oldTitleBar = titleBarWidget();
    setTitleBarWidget(new QWidget());
    delete oldTitleBar;

    // Add toplevel groups
    initializeResourceTree();
}

//****************************************************************************/
void MaterialTreeDockWidget::initializeResourceTree (void)
{
    // Initialize; add toplevel groups to the mResourceTreeWidget up front
    QtSourcesInfo info;

    // HLMS PBS
    mResourceTreeWidget->addResource (TOOL_SOURCES_LEVEL_X000_PBS,
                                      TOOL_SOURCES_LEVEL_X000_PBS,
                                      0,
                                      QString("PBS"),
                                      QString("PBS"),
                                      ICON_PBS_DATABLOCK_NO_PATH);
    info.toplevelId = TOOL_SOURCES_LEVEL_X000_PBS;
    info.resourceId = TOOL_SOURCES_LEVEL_X000_PBS;
    info.resourceType = Magus::TOOL_RESOURCETREE_KEY_TYPE_TOPLEVEL_GROUP;
    info.parentId = 0;
    info.fileName = QString("PBS");
    info.baseName = info.fileName;
    //info.filter = TOOL_SOURCES_FORMAT_PBS;
    info.filter = QString("");
    info.baseNameThumb = ICON_PBS_DATABLOCK;
    mSourceInfo[TOOL_SOURCES_LEVEL_X000_PBS] = info;

    // HLMS UNLIT
    mResourceTreeWidget->addResource (TOOL_SOURCES_LEVEL_X000_UNLIT,
                                      TOOL_SOURCES_LEVEL_X000_UNLIT,
                                      0,
                                      QString("Unlit"),
                                      QString("Unlit"),
                                      ICON_UNLIT_DATABLOCK_NO_PATH);
    info.toplevelId = TOOL_SOURCES_LEVEL_X000_UNLIT;
    info.resourceId = TOOL_SOURCES_LEVEL_X000_UNLIT;
    info.resourceType = Magus::TOOL_RESOURCETREE_KEY_TYPE_TOPLEVEL_GROUP;
    info.parentId = 0;
    info.fileName = QString("Unlit");
    info.baseName = info.fileName;
    //info.filter = TOOL_SOURCES_FORMAT_UNLIT;
    info.filter = QString("");
    info.baseNameThumb = ICON_UNLIT_DATABLOCK;
    mSourceInfo[TOOL_SOURCES_LEVEL_X000_UNLIT] = info;

    // Determine what is enabled/disabled if a toplevelgroup is selected
    mResourceTreeWidget->enableContextMenuItemForTopLevelGroup(mResourceTreeWidget->mActionCreateToplevelGroupText, false);
    mResourceTreeWidget->enableContextMenuItemForTopLevelGroup(mResourceTreeWidget->mActionCreateSubGroupText, true);
    mResourceTreeWidget->enableContextMenuItemForTopLevelGroup(mResourceTreeWidget->mActionCreateAssetText, false);
    mResourceTreeWidget->enableContextMenuItemForTopLevelGroup(mResourceTreeWidget->mActionImportAssetText, false);
    mResourceTreeWidget->enableContextMenuItemForTopLevelGroup(mResourceTreeWidget->mActionDuplicateAssetText, false);
    mResourceTreeWidget->enableContextMenuItemForTopLevelGroup(mResourceTreeWidget->mActionDeleteResourceText, false);
    mResourceTreeWidget->enableContextMenuItemForTopLevelGroup(ACTION_EDIT, false);

    // Determine what is enabled/disabled if a subgroup is selected
    mResourceTreeWidget->enableContextMenuItemForSubGroup(mResourceTreeWidget->mActionCreateToplevelGroupText, false);
    mResourceTreeWidget->enableContextMenuItemForSubGroup(mResourceTreeWidget->mActionCreateSubGroupText, true);
    mResourceTreeWidget->enableContextMenuItemForSubGroup(mResourceTreeWidget->mActionCreateAssetText, false);
    mResourceTreeWidget->enableContextMenuItemForSubGroup(mResourceTreeWidget->mActionImportAssetText, false);
    mResourceTreeWidget->enableContextMenuItemForSubGroup(mResourceTreeWidget->mActionDuplicateAssetText, false);
    mResourceTreeWidget->enableContextMenuItemForSubGroup(mResourceTreeWidget->mActionDeleteResourceText, true);
    mResourceTreeWidget->enableContextMenuItemForSubGroup(ACTION_EDIT, false);

    // Determine what is enabled/disabled if an asset is selected
    mResourceTreeWidget->enableContextMenuItemForAsset(mResourceTreeWidget->mActionCreateToplevelGroupText, false);
    mResourceTreeWidget->enableContextMenuItemForAsset(mResourceTreeWidget->mActionCreateSubGroupText, false);
    mResourceTreeWidget->enableContextMenuItemForAsset(mResourceTreeWidget->mActionCreateAssetText, false);
    mResourceTreeWidget->enableContextMenuItemForAsset(mResourceTreeWidget->mActionImportAssetText, false);
    mResourceTreeWidget->enableContextMenuItemForAsset(mResourceTreeWidget->mActionDuplicateAssetText, true);
    mResourceTreeWidget->enableContextMenuItemForAsset(mResourceTreeWidget->mActionDeleteResourceText, true);
    mResourceTreeWidget->enableContextMenuItemForAsset(ACTION_EDIT, true);
}

//****************************************************************************/
MaterialTreeDockWidget::~MaterialTreeDockWidget(void)
{
}

//****************************************************************************/
QVector<Magus::QtResourceInfo*>& MaterialTreeDockWidget::getResources (void)
{
    // Delegate to mResourceTreeWidget; this is the component that actually retrieves the data
    return mResourceTreeWidget->getResources();
}

//****************************************************************************/
void MaterialTreeDockWidget::setResources(const QVector<Magus::QtResourceInfo*>& resources)
{
    // Add resources to the resource tree
    mResourceTreeWidget->setResources(resources, true);

    // Iterate again through the list to make sure that the thumb info is set
    QVectorIterator<Magus::QtResourceInfo*> it(resources);
    it.toFront();
    Magus::QtResourceInfo* resourceInfo;
    while (it.hasNext())
    {
        resourceInfo = it.next();
        QtSourcesInfo info;
        info.toplevelId = resourceInfo->topLevelId;
        info.resourceId = resourceInfo->resourceId;
        info.resourceType = resourceInfo->resourceType;
        info.parentId = resourceInfo->parentId;
        info.fileName = resourceInfo->fullQualifiedName;
        info.baseName = resourceInfo->resourceName;
        info.baseNameThumb = resourceInfo->resourceName + QString (".png"); // Do not forget
        mSourceInfo[resourceInfo->resourceId] = info;
    }

    mResourceTreeWidget->expandAll();
}

//****************************************************************************/
const QString& MaterialTreeDockWidget::getSelectedFullQualifiedName(void)
{
    QTreeWidgetItem* item = mResourceTreeWidget->getSelectedResourceItem ();
    if (item)
    {
        if (mResourceTreeWidget->isItemAsset(item))
            return mResourceTreeWidget->getFullQualifiedNameFromItem(item);
    }

    return mEmptyString;
}

//****************************************************************************/
bool MaterialTreeDockWidget::addMaterial(const QString& baseNameJson,
                                      const QString& fullNameJson,
                                      const QString& baseNameThumb,
                                      EditorHlmsTypes type)
{
    switch (type)
    {
        case HLMS_PBS:
        {
            return addAssetQuiet(TOOL_SOURCES_LEVEL_X000_PBS, fullNameJson, baseNameJson, baseNameThumb);
        }
        break;

        case HLMS_UNLIT:
        {
            return addAssetQuiet(TOOL_SOURCES_LEVEL_X000_UNLIT, fullNameJson, baseNameJson, baseNameThumb);
        }
        break;
    }
}

//****************************************************************************/
void MaterialTreeDockWidget::selectTopLevel(int toplevelId)
{
    mResourceTreeWidget->selectResource(toplevelId, false);
}

//****************************************************************************/
void MaterialTreeDockWidget::clearContent(void)
{
    mResourceTreeWidget->clear();
    initializeResourceTree();
}

//****************************************************************************/
bool MaterialTreeDockWidget::addAssetQuiet(int toplevelId,
                                           const QString& name,
                                           const QString& baseName,
                                           const QString& baseNameThumb)
{
    // Always add it even if the resource exists (sometimes the resourcetree and mSourceInfo are out-of-sync)
    if (isResourceExisting(baseName))
    {
        // delete it first
        deleteAssetQuiet(toplevelId, name, baseName);
    }

    // Suppress the signal that a resource was added, otherwise the signal causes the asset to
    // be added to the asset widget
    int resourceId = mResourceTreeWidget->addResource(toplevelId, baseName, name, name, true, true);
    mResourceTreeWidget->expand(toplevelId);

    // Also add/set it to mSourceInfo
    QtSourcesInfo info;
    info.toplevelId = toplevelId;
    info.resourceId = resourceId;
    info.resourceType = Magus::TOOL_RESOURCETREE_KEY_TYPE_ASSET; // It is an asset
    info.parentId = toplevelId;
    info.fileName = name;
    info.baseName = baseName;
    info.baseNameThumb = baseNameThumb;
    mSourceInfo[resourceId] = info;
    return true;
}

//****************************************************************************/
const QString& MaterialTreeDockWidget::setSelectAssetQuiet(const QString& baseNameThumb)
{
    int id = getResourceId(baseNameThumb);
    if (id != -1)
    {
        mResourceTreeWidget->selectResource(id, false);
        return mSourceInfo[id].fileName;
    }

    return mEmptyString;
}

//****************************************************************************/
const QString& MaterialTreeDockWidget::doubleClicked(const QString& baseNameThumb)
{
    int id = getResourceId(baseNameThumb);
    if (id != -1)
    {
        return mSourceInfo[id].fileName;
    }

    return mEmptyString;
}

//****************************************************************************/
void MaterialTreeDockWidget::deleteAssetQuiet(int toplevelId, const QString& name, const QString& baseName)
{
    // First, delete it from mResourceTreeWidget
    int resourceId = mResourceTreeWidget->getResourceIdFromToplevelIdAndName(toplevelId, name);
    if (resourceId < 0)
        return;

    mResourceTreeWidget->deleteResource(resourceId, true);

    // find the underlying asset (filenames) + delete it from the mSourceInfo
    mSourceInfo.remove(resourceId);
}

//****************************************************************************/
void MaterialTreeDockWidget::deleteAssetQuiet(const QString& baseNameThumb)
{
    int id = getResourceId(baseNameThumb);
    if (id != -1)
    {
        QtSourcesInfo info = mSourceInfo[id];
        mSourceInfo.remove(id);
        mResourceTreeWidget->deleteResource(info.toplevelId, info.fileName, true);
    }
}

//****************************************************************************/
void MaterialTreeDockWidget::handleResourceSelected(int resourceId)
{
    // Determine which type is selected
    QMap<int, QtSourcesInfo>::iterator it = mSourceInfo.find(resourceId);
    if (it != mSourceInfo.end())
    {
        QtSourcesInfo info = it.value();
        mResourceTreeWidget->setSubgroupIconName(determineSubgroupIcon(info.toplevelId));
        emit resourceSelected(info.toplevelId, info.parentId, info.resourceId, info.fileName, info.baseNameThumb);
        //QMessageBox::information(0, QString("this"), QVariant(info.toplevelId).toString()); // test
    }
}

//****************************************************************************/
void MaterialTreeDockWidget::handleResourceDoubleClicked(int resourceId)
{
    // Determine which type is selected
    QMap<int, QtSourcesInfo>::iterator it = mSourceInfo.find(resourceId);
    if (it != mSourceInfo.end())
    {
        QtSourcesInfo info = it.value();
        if (info.resourceType == Magus::TOOL_RESOURCETREE_KEY_TYPE_ASSET)
        {
            // Do not do something specific for a double click on a toplevel group or a (sub)group
            mResourceTreeWidget->setSubgroupIconName(determineSubgroupIcon(info.toplevelId));
            emit resourceDoubleClicked(info.toplevelId, info.parentId, info.resourceId, info.fileName, info.baseNameThumb);
        }
    }
}

//****************************************************************************/
void MaterialTreeDockWidget::handleResourceAdded(int resourceId)
{
    QtSourcesInfo info;
    int toplevelId = mResourceTreeWidget->getToplevelParentId(resourceId);
    QString name = mResourceTreeWidget->getResourceName(resourceId);
    QString fullQualifiedName = mResourceTreeWidget->getFullQualifiedName(resourceId);
    info.toplevelId = toplevelId;
    info.resourceId = resourceId;
    info.resourceType = mResourceTreeWidget->getTypeFromResourceId(resourceId);
    info.parentId = mResourceTreeWidget->getParentId(resourceId);
    info.fileName = fullQualifiedName;
    info.baseName = name;
    mSourceInfo[resourceId] = info;

    // Emit file info to MaterialMain, because the MaterialThumbsDockWidget must be appended with the new files
    // Do this only in case the resource is an asset
    if (mResourceTreeWidget->isResourceAsset(resourceId))
        emit resourceAdded(info.toplevelId, info.parentId, info.resourceId, info.fileName, info.baseName);
}

//****************************************************************************/
void MaterialTreeDockWidget::handleResourceDeleted(int resourceId)
{
    // Do not handle resources with resourceId = 0
    if (resourceId == 0)
        return;

    // Get all the underlying assets (filenames) + delete them from the mSourceInfo
    foreach(QtSourcesInfo info, mSourceInfo)
    {
        if (info.parentId == resourceId)
            handleResourceDeleted(info.resourceId);
        else if (info.resourceId == resourceId)
        {
            // Delete from mSourceInfo (emit with thumb texture parameters)
            emit resourceDeleted(info.toplevelId,
                                 info.parentId,
                                 info.resourceId,
                                 THUMBS_PATH.c_str() + info.baseNameThumb,
                                 info.baseNameThumb);
            mSourceInfo.remove(resourceId);
        }
    }
}

//****************************************************************************/
void MaterialTreeDockWidget::handleResourceMoved(int resourceId)
{
    // Search the info object
    QtSourcesInfo info;
    QMap<int, QtSourcesInfo>::iterator it = mSourceInfo.find(resourceId);
    if (it == mSourceInfo.end())
        return;

    // Update the parentId and toplevelId (Although in this version it is not possible to move to a different toplevel)
    // Emitting again is not needed, because nothing changed in the assets widget
    info = it.value();
    info.toplevelId = mResourceTreeWidget->getToplevelParentId(resourceId);
    info.parentId = mResourceTreeWidget->getParentId(resourceId);
    mSourceInfo[resourceId] = info; // Overwrite existing one
}

//****************************************************************************/
void MaterialTreeDockWidget::handleResourceSearched(const QString& searchPattern)
{
    // Signal
    emit resourceSearched(searchPattern);
}

//****************************************************************************/
void MaterialTreeDockWidget::handleResourceSearchReset(void)
{
    // Signal
    emit resourceSearchReset();
}

//****************************************************************************/
void MaterialTreeDockWidget::handleResourceDuplicated(int resourceId)
{
    // Determine which type is selected
    QMap<int, QtSourcesInfo>::iterator it = mSourceInfo.find(resourceId);
    if (it != mSourceInfo.end())
    {
        QtSourcesInfo info = it.value();
        if (info.resourceType == Magus::TOOL_RESOURCETREE_KEY_TYPE_ASSET)
        {
            // Do not do something specific for a clone on a toplevel group or a (sub)group
            mResourceTreeWidget->setSubgroupIconName(determineSubgroupIcon(info.toplevelId));
            emit resourceCloned(info.toplevelId, info.parentId, info.resourceId, info.fileName, info.baseName, info.baseNameThumb);
        }
    }
}

//****************************************************************************/
void MaterialTreeDockWidget::handleCustomContextMenuItemSelected(const QString& menuItemText,
                                                                 int resourceId)
{
    if (menuItemText == ACTION_EDIT)
    {
        // Determine which type is selected
        QMap<int, QtSourcesInfo>::iterator it = mSourceInfo.find(resourceId);
        if (it != mSourceInfo.end())
        {
            QtSourcesInfo info = it.value();
            if (info.resourceType == Magus::TOOL_RESOURCETREE_KEY_TYPE_ASSET)
            {
                // Do not do something specific for a double click on a toplevel group or a (sub)group
                mResourceTreeWidget->setSubgroupIconName(determineSubgroupIcon(info.toplevelId));
                emit resourceDoubleClicked(info.toplevelId, info.parentId, info.resourceId, info.fileName, info.baseNameThumb);
            }
        }
    }
}


//****************************************************************************/
bool MaterialTreeDockWidget::isResourceExisting(const QString& baseName)
{
    QMap<int, QtSourcesInfo>::iterator iter;
    QMap<int, QtSourcesInfo>::iterator iterStart = mSourceInfo.begin();
    QMap<int, QtSourcesInfo>::iterator iterEnd = mSourceInfo.end();
    for (iter = iterStart; iter != iterEnd; ++iter)
    {
        QtSourcesInfo info = iter.value();
        if (baseName == info.baseName)
            return true;
    }

    return false;
}

//****************************************************************************/
int MaterialTreeDockWidget::getResourceId(const QString& baseNameThumb)
{
    QMap<int, QtSourcesInfo>::iterator iter;
    QMap<int, QtSourcesInfo>::iterator iterStart = mSourceInfo.begin();
    QMap<int, QtSourcesInfo>::iterator iterEnd = mSourceInfo.end();
    for (iter = iterStart; iter != iterEnd; ++iter)
    {
        QtSourcesInfo info = iter.value();
        if (baseNameThumb == info.baseNameThumb)
            return info.resourceId;
    }

    return -1;
}

//****************************************************************************/
const QString& MaterialTreeDockWidget::determineSubgroupIcon(int toplevelId)
{
    if (toplevelId == TOOL_SOURCES_LEVEL_X000_PBS)
        return ICON_PBS_DATABLOCK_SMALL_NO_PATH;
    else if (toplevelId == TOOL_SOURCES_LEVEL_X000_UNLIT)
        return ICON_UNLIT_DATABLOCK_SMALL_NO_PATH;
    else
        return mEmptyString;
}


