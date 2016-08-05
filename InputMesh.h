#ifndef __InputMesh_h__
#define __InputMesh_h__

#include "Input.h"

#include <HAPI/HAPI.h>

class MFnMesh;
class MObjectArray;
class MStringArray;

class InputMesh : public Input
{
    public:
        InputMesh(int nodeId, int inputIdx);
        virtual ~InputMesh();

        virtual AssetInputType assetInputType() const;

        virtual void setInputTransform(MDataHandle &dataHandle);
        virtual void setInputGeo(
                MDataBlock &dataBlock,
                const MPlug &plug
                );

    protected:
        bool processPoints(
                const MFnMesh &meshFn
                );
        bool processNormals(
                const MFnMesh &meshFn,
                std::vector<int> vertexCount
                );
        bool processUVs(
                const MFnMesh &meshFn,
                std::vector<int> vertexCount,
                std::vector<int> vertexList
                );
        bool processColorSets(
                const MFnMesh &meshFn,
                std::vector<int> vertexCount,
                std::vector<int> vertexList
                );
        bool processSets(
                const MPlug &plug,
                const MFnMesh &meshFn
                );
        bool processShadingGroups(
                const MFnMesh &meshFn,
                const MStringArray &sgNames,
                const MObjectArray &sgCompObjs
                );

    protected:
        HAPI_NodeId myInputNodeId;
};

#endif
