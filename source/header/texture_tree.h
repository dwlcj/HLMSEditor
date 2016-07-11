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

#ifndef TEXTURE_TREE_H
#define TEXTURE_TREE_H

#include <QtWidgets>
#include <QMenu>
#include <QAction>
#include <QMessageBox>
#include <QToolBar>
#include <QTabWidget>
#include "constants.h"
#include "tool_resourcetree_widget.h"

QT_BEGIN_NAMESPACE
class QDockWidget;
QT_END_NAMESPACE

/****************************************************************************
TextureTreeDockWidget class
***************************************************************************/
class TextureTreeDockWidget : public QDockWidget
{
    Q_OBJECT

    public:
        TextureTreeDockWidget(const QString& iconDir, const QString& title, QMainWindow* parent, Qt::WindowFlags flags = 0);
        ~TextureTreeDockWidget(void);

        // Returns a list of all resources in the resource tree. This includes both groups, subgroups and assets
        QVector<Magus::QtResourceInfo*>& getResources (void);

        // Returns a list of all resources in the resource tree which are under this resourceId (assuming it is a parent)
        QVector<Magus::QtResourceInfo*>& getResources (int resourceId);

        // Set the resources
        void setResources (const QVector<Magus::QtResourceInfo*>& resources);

        void initializeResourceTree (void);

        // Add the name of a texture file
        void addTextureFile (const QString& fileName);
        void addTextureFile (const QString& fileName, int groupId);
        int addGroup (const QString& group);

        // Delete a texture file
        void deleteTextureFile(const QString& fileName);

        // Check whether a texture filename exists
        bool isResourceExisting(const QString& fileName);

        void expand (int resourceId);
        const QString& getCurrentFileName (void);
        const QString& getCurrentThumb (void);
        const QString& setSelectAssetQuiet(const QString& fileName); // This differs from the one in material_tree.h
        int getResourceId(const QString& fileName);

        // Clear all content in the resourcetree
        void clearContent(void);

    signals:
        void resourceSelected(int toplevelId, int parentId, int resourceId, const QString& name, const QString& baseName, int resourceType);
        void resourceDoubleClicked(int toplevelId, int parentId, int resourceId, const QString& name, const QString& baseName);
        void resourceDeleted(int toplevelId, int parentId, int resourceId, const QString& name, const QString& baseName);
        void resourceMoved(int toplevelId, int parentId, int resourceId, const QString& name, const QString& baseName, int resourceType);
        void resourceChanged(int toplevelId, int parentId, int resourceId, const QString& name, const QString& baseName, int resourceType);
        void resourceAdded(int toplevelId, int parentId, int resourceId, const QString& name, const QString& baseName, int resourceType);
        void resourceSearched(const QString& searchPattern);
        void resourceSearchReset(void);
        void customContextMenuItemSelected(const QString& menuItemText);

    private slots:
        void handleResourceSelected(int resourceId);
        void handleResourceDoubleClicked(int resourceId);
        void handleResourceAdded(int resourceId);
        void handleResourceDeleted(int resourceId);
        void handleResourceMoved(int resourceId);
        void handleResourceChanged(int resourceId);
        void handleResourceSearched(const QString& searchPattern);
        void handleResourceSearchReset(void);
        void handleCustomContextMenuItemSelected(const QString& menuItemText, int resourceId);

    private:
        QMainWindow* mParent;
        QMainWindow* mInnerMain;
        Magus::QtResourceTreeWidget* mResourceTreeWidget;
        QString mIconDir;
        QString mEmptyString;
        QString mTempString;
        QMap<int, QtSourcesInfo> mSourceInfo;
        QVector<Magus::QtResourceInfo*> mFilteredResources;
};

#endif

