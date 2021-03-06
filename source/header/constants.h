/****************************************************************************
**
** Copyright (C) 2016 - 2017
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

#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <QString>
#include <QMessageBox>
#include "OgreString.h"
#include "OgreColourValue.h"
#include "OgreMath.h"
#include "ogre3_widget.h"

//************************************ QString constants *******************************************/
static const QString WINDOW_TITLE = QString("HLMS editor");
static const int OGRE_WIDGET_RENDERWINDOW = 1;
static const int TB_ICON_AND_SPACING = 32;
static const QString NODE_TITLE_PBS_DATABLOCK = QString("Hlms PBS");
static const QString NODE_TITLE_UNLIT_DATABLOCK = QString("Hlms Unlit");
static const QString NODE_TITLE_SAMPLERBLOCK = QString("Texture/Samplerblock");
static const QString NODE_TITLE_MACROBLOCK = QString("Macroblock");
static const QString NODE_TITLE_BLENDBLOCK = QString("Blendblock");
static const unsigned int NODE_TYPE_PBS_DATABLOCK = 1;
static const unsigned int NODE_TYPE_UNLIT_DATABLOCK = 2;
static const unsigned int NODE_TYPE_SAMPLERBLOCK = 3;
static const unsigned int NODE_TYPE_MACROBLOCK = 4;
static const unsigned int NODE_TYPE_BLENDBLOCK = 5;
static const unsigned int MAX_SAMPLERBLOCKS = 8;
static const unsigned int MAX_MACROBLOCKS = 1;
static const unsigned int MAX_BLENDBLOCKS = 1;
static const unsigned int MAX_RECENT_HLMS_FILES = 9;
static const unsigned int MAX_RECENT_PROJECT_FILES = 9;
static const QString ICON_PATH = QString("../common/icons/");
static const QString ASSET_ICON_COLLAPSE = QString("../common/icons/collapse.png");
static const QString ASSET_ICON_EXPAND = QString("../common/icons/expand.png");
static const QString ICON_PBS_DATABLOCK = QString("../common/icons/pbs.png");
static const QString ICON_UNLIT_DATABLOCK = QString("../common/icons/unlit.png");
static const QString ICON_SAMPLERBLOCK = QString("../common/icons/samplerblock.png");
static const QString ICON_MACROBLOCK = QString("../common/icons/macroblock.png");
static const QString ICON_BLENDBLOCK = QString("../common/icons/blendblock.png");
static const QString ICON_GENERATE = QString("../common/icons/generate.png");
static const QString ICON_MINMAX = QString("../common/icons/minmax.png");
static const QString ICON_CLOSE = QString("../common/icons/close.png");
static const QString ICON_COLOUR = QString("../common/icons/colour.png");
static const QString ICON_INFO = QString("../common/icons/info.png");
static const QString ICON_MODEL = QString("../common/icons/model.png");
static const QString ICON_LIGHT = QString("../common/icons/lightbulb.png");
static const QString ICON_MOVE_TEXTURE_ON = QString("../common/icons/move_on.png");
static const QString ICON_MOVE_TEXTURE_OFF = QString("../common/icons/move_off.png");
static const QString ICON_PAINT_ON = QString("../common/icons/paint_on.png");
static const QString ICON_PAINT_OFF = QString("../common/icons/paint_off.png");
static const QString ICON_MARKER = QString("../common/icons/marker.png");
static const QString ICON_HOOVER_ON = QString("../common/icons/hoover_on.png");
static const QString ICON_HOOVER_OFF = QString("../common/icons/hoover_off.png");
static const QString ICON_UNDO_ON = QString("../common/icons/undo_on.png");
static const QString ICON_UNDO_OFF = QString("../common/icons/undo_off.png");
static const QString ICON_REDO_OFF = QString("../common/icons/redo_off.png");
static const QString ICON_REDO_ON = QString("../common/icons/redo_on.png");
static const QString ICON_SAMPLER_CLIPBOARD = QString("../common/icons/samplerblock_banner.png");
static const QString ICON_PIN = QString("../common/icons/pin.png");

static const QString ICON_HLMS = QString("../common/icons/HLMSEditor.png");
static const QString ICON_PBS_DATABLOCK_NO_PATH = QString("pbs.png");
static const QString ICON_PBS_DATABLOCK_SMALL_NO_PATH = QString("pbs_small.png");
static const QString ICON_UNLIT_DATABLOCK_NO_PATH = QString("unlit.png");
static const QString ICON_UNLIT_DATABLOCK_SMALL_NO_PATH = QString("unlit_small.png");
static const QString ICON_TEXTURE_NO_PATH = QString("samplerblock.png");
static const QString ICON_TEXTURE_SMALL_NO_PATH = QString("samplerblock_small.png");
static const QString HLMS_GROUP = "[Hlms]\n";
static const QString HLMS_DO_NOT_USE_AS_RESOURCE = "DoNotUseAsResource = ../common/ogre3\n"; // This must be the location where the HLMS templates are
static const QString INFO_PBS = QString("../common/info/hlms_pbs.inf");
static const QString INFO_UNLIT = QString("../common/info/hlms_unlit.inf");
static const QString INFO_SAMPLERBLOCK = QString("../common/info/samplerblock.inf");
static const QString INFO_MACROBLOCK = QString("../common/info/macroblock.inf");
static const QString INFO_BLENDBLOCK = QString("../common/info/blendblock.inf");
static const QString DEFAULT_PROJECT_NAME = QString("project1");
static const QString HEADER_PROJECT = QString("hlmsEditor v1.0");
static const QString FILE_MATERIAL_BROWSER = QString("materials.cfg");
static const QString FILE_TEXTURE_BROWSER = QString("textures.cfg");
static const QString FILE_RECENT_HLMS_FILES = QString("rhlms.cfg");
static const QString FILE_RECENT_PROJECT_FILES = QString("rprojects.cfg");
static const QString FILE_NO_IMAGE = QString("../common/icons/noImage.png");
static const QString FILE_RESOURCES_D = QString("resources_d.cfg");
static const QString FILE_RESOURCES = QString("resources.cfg");
static const QString FILE_RESOURCES_DEFAULT = QString("resources_default.cfg");
static const QString FILE_SETTINGS = QString("settings.cfg");
static const QString FILE_SETTINGS_DEFAULT = QString("settings_default.cfg");
static const QString PROJECT_PATH = "../project/";
static const QString DEFAULT_IMPORT_PATH = "../import/";
static const QString SETTINGS_GROUP_GENERAL = "General";
static const QString SETTINGS_IMPORT_PATH = "importPath";
static const QString SETTINGS_SAMPLERBLOCK_FILTER_INDEX = "samplerblockFilterIndex";
static const QString SETTINGS_NUMBER_OF_SKYBOXES = "numberOfSkyboxes";
static const QString SETTINGS_PREFIX_SKYBOX = "skybox";
static const QString NO_SKYBOX = "None";
static const QString MESH_VERSION_1 = QString("[MeshSerializer_v1");
static const QString MESH_VERSION_2 = QString("[MeshSerializer_v2");

static const QString PBSM_DIFFUSE_QSTRING = QString("Diffuse map");
static const QString PBSM_NORMAL_QSTRING = QString("Normal map");
static const QString PBSM_SPECULAR_QSTRING = QString("Specular / Metallic map");
static const QString PBSM_ROUGHNESS_QSTRING = QString("Roughness map");
static const QString PBSM_DETAIL_WEIGHT_QSTRING = QString("Detail weight map");
static const QString PBSM_DETAIL0_QSTRING = QString("Detail map 0");
static const QString PBSM_DETAIL1_QSTRING = QString("Detail map 1");
static const QString PBSM_DETAIL2_QSTRING = QString("Detail map 2");
static const QString PBSM_DETAIL3_QSTRING = QString("Detail map 30");
static const QString PBSM_DETAIL0_NM_QSTRING = QString("Detail normal map 0");
static const QString PBSM_DETAIL1_NM_QSTRING = QString("Detail normal map 1");
static const QString PBSM_DETAIL2_NM_QSTRING = QString("Detail normal map 2");
static const QString PBSM_DETAIL3_NM_QSTRING = QString("Detail normal map 3");
static const QString PBSM_REFLECTION_QSTRING = QString("Env. probe map");
static const QString PAINT_EFFECT_COLOR_QSTRING = QString("Colour");
static const QString PAINT_EFFECT_ERASE_QSTRING = QString("Erase");
static const QString PAINT_EFFECT_ALPHA_QSTRING = QString("Alpha");
static const QString PAINT_EFFECT_TEXTURE_QSTRING = QString("Texture / Normal");
static const QString PAINT_EFFECT_CARBON_COPY_QSTRING = QString("Carbon Copy");
static const QString PAINT_EFFECT_SMUDGE_QSTRING = QString("Smudge");
static const QString PAINT_OVERFLOW_IGNORE_QSTRING = QString("Ignore");
static const QString PAINT_OVERFLOW_CONTINUE_QSTRING = QString("Continue");
static const QString PRESET_PATH_QSTRING = "../common/presets/";
static const QString DEFAULT_BRUSH_AND_PATH_QSTRING = QString("../common/brushes/brush_001.png");
static const QString CLIPBOARD_PATH_QSTRING = "../common/clipboard/";
static const QString TAB_QSTRING = "    ";
static const QString TWO_TAB_QSTRING = "       ";

//************************************ Ogre String constants *******************************************/
static const Ogre::String DEFAULT_DATABLOCK_NAME = "[Default]";
static const Ogre::String DATABLOCK_DEBUG_CUBE = "DebugCube";
static const Ogre::String THUMBS_PATH = "../common/thumbs/";
static const Ogre::String BRUSH_PATH = "../common/brushes/";
static const Ogre::String DEFAULT_BRUSH = "brush_001.png";
static const Ogre::String TEMP_PATH = "../temp/";

//******************************************************************************************************/
// Static function to determine the 'resources' file
static const QString& getResourcesCfg (void)
{
    #if OGRE_DEBUG_MODE
        return FILE_RESOURCES_D;
    #else
        return FILE_RESOURCES;
    #endif
}

typedef enum
{
    HLMS_PBS,       /// Physically Based Shader Generator
    HLMS_UNLIT,     /// Made for GUIs, overlays, particle FXs, self-iluminating billboards
    HLMS_NONE
} EditorHlmsTypes;

/****************************************************************************
Struct for source info
***************************************************************************/
struct QtSourcesInfo
{
    int resourceId;
    int toplevelId;
    int parentId;
    int resourceType;
    QString fileName;
    QString baseName;
    QString fileDialogTitle;
    QString filter;
    QString baseNameThumb;
};

static unsigned int gSequence = 0;
//******************************************************************************************************/
static unsigned int getSequence(void)
{
    return ++gSequence;
}

//******************************************************************************************************/

static QString getBaseFileName(QString& fileName)
{
    QString mTempString = fileName;
    int index = mTempString.lastIndexOf('/');
    if (index < 0)
        index = mTempString.lastIndexOf('\\');

    if (index != 0)
        return mTempString.right(fileName.length() - index - 1);

    return mTempString;
}

//******************************************************************************************************/

static float randomBetweenTwoFloats(float min, float max)
{
    return Ogre::Math::RangeRandom(min, max);
}

//******************************************************************************************************/

static int randomBetweenTwoInts(int min, int max)
{
    return Ogre::Math::RangeRandom(min, max);
}

//******************************************************************************************************/

static Ogre::ColourValue randomBetweenTwoColours (const Ogre::ColourValue& paintColourMin, const Ogre::ColourValue& paintColourMax)
{
    return Ogre::ColourValue (randomBetweenTwoFloats (paintColourMin.r, paintColourMax.r),
                              randomBetweenTwoFloats (paintColourMin.g, paintColourMax.g),
                              randomBetweenTwoFloats (paintColourMin.b, paintColourMax.b),
                              randomBetweenTwoFloats (paintColourMin.a, paintColourMax.a));
}

//******************************************************************************************************/

static bool randomBool(void)
{
    return randomBetweenTwoInts (0, 2) - 1;
}

//******************************************************************************************************/

// Contextmenu action
static const QString ACTION_SET_CURRENT_MATERIAL = QString("Apply current material to (sub)mesh");
static const QString ACTION_TOGGLE_LIGHT_DIRECTION = QString("Set light direction");
static const QString ACTION_RESET_CAMERA = QString("Reset camera position/direction");
static const QString ACTION_TOGGLE_SUBMESH_SELECTION = QString("Toggle Mesh/Submesh selection");
static const QString ACTION_MOVE_TEXTURE = QString("Offset texture");
static const QString ACTION_TOGGLE_PAINT = QString("Paint");
static const QString ACTION_UNDO_PAINT = QString("Undo paint");
static const QString ACTION_REDO_PAINT = QString("Redo paint");
static const QString ACTION_SELECT_BACKGROUND_COLOUR = QString("Select background colour");

//******************************************************************************************************/

// Ports
static const QString PORT_DATABLOCK = QString("Hlms");
static const QString PORT_SAMPLERBLOCK = QString("Texture/Samplerblock");
static const QString PORT_MACROBLOCK = QString("Macroblock");
static const QString PORT_BLENDBLOCK = QString("Blendblock");
static const unsigned int PORT_ID_PBS_DATABLOCK = 10;
static const unsigned int PORT_ID_UNLIT_DATABLOCK = 20;
static const unsigned int PORT_ID_SAMPLERBLOCK = 30;
static const unsigned int PORT_ID_MACROBLOCK = 40;
static const unsigned int PORT_ID_BLENDBLOCK = 50;

//******************************************************************************************************/

// Properties
static const int CONTAINER_BLENDBLOCK_GENERAL = 10;
static const int CONTAINER_MACROBLOCK_GENERAL = 20;
static const int CONTAINER_PBS_DATABLOCK_GENERAL = 30;
static const int CONTAINER_PBS_DATABLOCK_COLOUR = 40;
static const int CONTAINER_UNLIT_DATABLOCK_GENERAL = 50;
static const int CONTAINER_SAMPLERBLOCK_GENERAL = 60;
static const int CONTAINER_SAMPLERBLOCK_DETAILS = 70;
static const int CONTAINER_SAMPLERBLOCK_DETAIL_MAP_DETAILS = 80;

// PSB Datablock properties
static const QString DEFAULT_PBS_DATABLOCK_NAME = QString("HlmsPbs");
static const int PROPERTY_PBS_DATABLOCK_NAME = 11;
static const int PROPERTY_PBS_DATABLOCK_DIFFUSE = 12;
static const int PROPERTY_PBS_DATABLOCK_BACKGROUND = 13;
static const int PROPERTY_PBS_DATABLOCK_SPECULAR = 14;
static const int PROPERTY_PBS_DATABLOCK_ROUGHNESS = 15;
static const int PROPERTY_PBS_DATABLOCK_WORKFLOW = 16;
static const int PROPERTY_PBS_DATABLOCK_METALNESS = 17;
static const int PROPERTY_PBS_DATABLOCK_SEPARATE_FRESNEL = 18;
static const int PROPERTY_PBS_DATABLOCK_FRESNEL_R = 19;
static const int PROPERTY_PBS_DATABLOCK_FRESNEL_G = 20;
static const int PROPERTY_PBS_DATABLOCK_FRESNEL_B = 21;
static const int PROPERTY_PBS_DATABLOCK_TRANPARENCEY_VALUE = 22;
static const int PROPERTY_PBS_DATABLOCK_TRANPARENCY_MODE = 23;
static const int PROPERTY_PBS_DATABLOCK_TWO_SIDED_LIGHTING = 24;
static const int PROPERTY_PBS_DATABLOCK_USE_ALPHA_FROM_TEXTURES = 25;
static const int PROPERTY_PBS_DATABLOCK_BRDF = 26;
static const int PROPERTY_PBS_DATABLOCK_ALPHATEST = 27;
static const int PROPERTY_PBS_DATABLOCK_ALPHATEST_THRESHOLD = 28;

// Unlit Datablock properties
static const QString DEFAULT_UNLIT_DATABLOCK_NAME = QString("HlmsUnlit");
static const int PROPERTY_UNLIT_DATABLOCK_NAME = 11;
static const int PROPERTY_UNLIT_DATABLOCK_COLOUR = 12;
static const int PROPERTY_UNLIT_DATABLOCK_ALPHATEST = 13;
static const int PROPERTY_UNLIT_DATABLOCK_ALPHATEST_THRESHOLD = 14;

// Samplerblock properties
static const int PROPERTY_SAMPLERBLOCK_TEXTURE = 40;
static const int PROPERTY_SAMPLERBLOCK_TEXTURE_TYPE = 41;
static const int PROPERTY_SAMPLERBLOCK_ENABLED = 42;
static const int PROPERTY_SAMPLERBLOCK_TEXTURE_MIN_FILTER = 43;
static const int PROPERTY_SAMPLERBLOCK_TEXTURE_MAG_FILTER = 44;
static const int PROPERTY_SAMPLERBLOCK_TEXTURE_MIP_FILTER = 45;
static const int PROPERTY_SAMPLERBLOCK_ADDRESSING_MODE_U = 46;
static const int PROPERTY_SAMPLERBLOCK_ADDRESSING_MODE_V = 47;
static const int PROPERTY_SAMPLERBLOCK_ADDRESSING_MODE_W = 48;
static const int PROPERTY_SAMPLERBLOCK_MIPLOD_BIAS = 49;
static const int PROPERTY_SAMPLERBLOCK_MAX_ANISOTROPY = 50;
static const int PROPERTY_SAMPLERBLOCK_COMPARE_FUNCTION = 51;
static const int PROPERTY_SAMPLERBLOCK_MIN_LOD = 52;
static const int PROPERTY_SAMPLERBLOCK_MAX_LOD = 53;
static const int PROPERTY_SAMPLERBLOCK_BORDER_COLOUR = 54;
static const int PROPERTY_SAMPLERBLOCK_UV_SET = 55;
static const int PROPERTY_SAMPLERBLOCK_BLEND_MODE = 56;
static const int PROPERTY_SAMPLERBLOCK_MAP_WEIGTH = 57;
static const int PROPERTY_SAMPLERBLOCK_OFFSET_U = 58;
static const int PROPERTY_SAMPLERBLOCK_OFFSET_V = 59;
static const int PROPERTY_SAMPLERBLOCK_SCALE = 60;
static const int PROPERTY_SAMPLERBLOCK_ANIM_ENABLED = 61;
static const int PROPERTY_SAMPLERBLOCK_ANIM_SCALE = 62;
static const int PROPERTY_SAMPLERBLOCK_ANIM_TRANSLATE_U = 63;
static const int PROPERTY_SAMPLERBLOCK_ANIM_TRANSLATE_V = 64;
static const int PROPERTY_SAMPLERBLOCK_ANIM_ROTATE = 65;

// Macroblock properties
static const int PROPERTY_MACROBLOCK_ENABLED = 70;
static const int PROPERTY_MACROBLOCK_SCISSOR_TEST_ENABLED = 71;
static const int PROPERTY_MACROBLOCK_DEPTH_CHECK = 72;
static const int PROPERTY_MACROBLOCK_DEPTH_WRITE = 73;
static const int PROPERTY_MACROBLOCK_DEPTH_FUNCTION = 74;
static const int PROPERTY_MACROBLOCK_DEPTH_BIAS_CONSTANT = 75;
static const int PROPERTY_MACROBLOCK_DEPTH_BIAS_SLOPE_SCALE = 76;
static const int PROPERTY_MACROBLOCK_CULL_MODE = 77;
static const int PROPERTY_MACROBLOCK_POLYGON_MODE = 78;

// Blendblock properties
static const int PROPERTY_BLENDBLOCK_ENABLED = 90;
static const int PROPERTY_BLENDBLOCK_ALPHA_TO_COVERAGE = 91;
static const int PROPERTY_BLENDBLOCK_BLEND_CHANNEL_MASK = 92;
static const int PROPERTY_BLENDBLOCK_TRANSPARENT = 93;
static const int PROPERTY_BLENDBLOCK_SEPARATE_BLEND = 94;
static const int PROPERTY_BLENDBLOCK_SOURCE_BLEND_FACTOR = 95;
static const int PROPERTY_BLENDBLOCK_DEST_BLEND_FACTOR = 96;
static const int PROPERTY_BLENDBLOCK_SOURCE_BLEND_FACTOR_ALPHA = 97;
static const int PROPERTY_BLENDBLOCK_DEST_BLEND_FACTOR_ALPHA = 98;
static const int PROPERTY_BLENDBLOCK_BLEND_OPERATION = 99;
static const int PROPERTY_BLENDBLOCK_BLEND_OPERATION_ALPHA = 100;

// Paintlayer properties
static const int CONTAINER_PAINTLAYER_GENERAL = 1;
static const int CONTAINER_PAINTLAYER_CARBON_COPY = 2;
static const int CONTAINER_PAINTLAYER_COLOUR = 3;
static const int CONTAINER_PAINTLAYER_SMUDGE = 4;
static const int CONTAINER_PAINTLAYER_SCALE = 5;
static const int CONTAINER_PAINTLAYER_FORCE = 6;
static const int CONTAINER_PAINTLAYER_ROTATION_ANGLE = 7;
static const int CONTAINER_PAINTLAYER_TRANSLATION = 8;
static const int CONTAINER_PAINTLAYER_MIRROR_HORIZONTAL = 9;
static const int CONTAINER_PAINTLAYER_MIRROR_VERTICAL = 10;

static const int PROPERTY_TEXTURE_TYPE = 200;
static const int PROPERTY_PAINT_EFFECT = 201;
static const int PROPERTY_PAINT_OVERFLOW = 202;

static const int PROPERTY_CARBON_COPY_TEXTURE = 210;
static const int PROPERTY_CARBON_COPY_SCALE = 211;

static const int PROPERTY_PAINT_COLOUR = 220;
static const int PROPERTY_JITTER_PAINT_COLOUR_ENABLED = 221;
static const int PROPERTY_JITTER_PAINT_COLOUR_MIN = 222;
static const int PROPERTY_JITTER_PAINT_COLOUR_MAX = 223;
static const int PROPERTY_JITTER_PAINT_COLOUR_INTERVAL = 224;

static const int PROPERTY_SMUDGE_DECAY = 230;

static const int PROPERTY_SCALE = 240;
static const int PROPERTY_JITTER_SCALE_ENABLED = 241;
static const int PROPERTY_JITTER_SCALE_MIN = 242;
static const int PROPERTY_JITTER_SCALE_MAX = 243;
static const int PROPERTY_JITTER_SCALE_INTERVAL = 244;

static const int PROPERTY_FORCE = 250;
static const int PROPERTY_JITTER_FORCE_ENABLED = 251;
static const int PROPERTY_JITTER_FORCE_MIN = 252;
static const int PROPERTY_JITTER_FORCE_MAX = 253;
static const int PROPERTY_JITTER_FORCE_INTERVAL = 254;

static const int PROPERTY_ROTATION_ANGLE = 260;
static const int PROPERTY_JITTER_ROTATION_ANGLE_ENABLED = 261;
static const int PROPERTY_JITTER_ROTATION_ANGLE_MIN = 262;
static const int PROPERTY_JITTER_ROTATION_ANGLE_MAX = 263;
static const int PROPERTY_JITTER_ROTATION_ANGLE_INTERVAL = 264;

static const int PROPERTY_TRANSLATION_X = 270;
static const int PROPERTY_TRANSLATION_Y = 271;
static const int PROPERTY_JITTER_TRANSLATION_ENABLED = 272;
static const int PROPERTY_JITTER_TRANSLATION_X_MIN = 273;
static const int PROPERTY_JITTER_TRANSLATION_X_MAX = 274;
static const int PROPERTY_JITTER_TRANSLATION_Y_MIN = 275;
static const int PROPERTY_JITTER_TRANSLATION_Y_MAX = 276;
static const int PROPERTY_JITTER_TRANSLATION_INTERVAL = 277;

static const int PROPERTY_MIRROR_HORIZONTAL = 280;
static const int PROPERTY_JITTER_MIRROR_HORIZONTAL_ENABLED = 281;
static const int PROPERTY_JITTER_MIRROR_HORIZONTAL_INTERVAL = 282;

static const int PROPERTY_MIRROR_VERTICAL = 290;
static const int PROPERTY_JITTER_MIRROR_VERTICAL_ENABLED = 291;
static const int PROPERTY_JITTER_MIRROR_VERTICAL_INTERVAL = 292;

// Material and Texture browser
static const int TOOL_SOURCES_LEVEL_X000_PBS = 1;
static const int TOOL_SOURCES_LEVEL_X000_UNLIT = 2;
static const int TOOL_SOURCES_LEVEL_X000_TEXTURE = 3;
static const QString GROUP_NAME_IMPORTED_TEXTURES = QString("Imported resources");
static const QString ACTION_IMPORT_TEXTURES_FROM_DIR = QString("Import from directory");
static const QString ACTION_CONFIGURE = QString("Configure");
static const QString ACTION_ADD_TEXTURES = QString("Add texture file(s)");
static const QString ACTION_EDIT = QString("Edit material");
static const QString ACTION_MOVE_TO_NODE_EDITOR = QString("Move to node editor");
static const QString ACTION_REMOVE_FROM_LIST = QString("Remove from list");

// Painting
static const unsigned short PAINT_MAX_MIP_MAPS = 7;
static const QString ACTION_NEW_PAINTING_LAYER = QString("Create paint layer");
static const QString ACTION_EDIT_PAINTING_LAYER = QString("Edit paint layer");
static const QString ACTION_DELETE_CURRENT_PAINT_LAYERS = QString("Delete selected paint layer");
static const int TEXTURE_FILE_GENERATION_DEPTH = 5; // Determines number of undo's

// Brushes
static const QString ACTION_SET_BRUSH = QString("Set brush in current paint layer");

// Presets
static const QString ACTION_CREATE_PRESET_MATERIAL = QString("Create material from preset");
static const QString ACTION_CREATE_AND_APPLY_PRESET = QString("Create material from preset and apply");
static const QString ACTION_DELETE_PRESET = QString("Delete preset");

// Clipboard
static const QString ACTION_USE_CURRENT_CLIP = QString("Use selected clip");
static const QString ACTION_DELETE_CURRENT_CLIP = QString("Delete selected clip");

#endif
