//
// Copyright 2016 Pixar
//
// Licensed under the Apache License, Version 2.0 (the "Apache License")
// with the following modification; you may not use this file except in
// compliance with the Apache License and the following modification to it:
// Section 6. Trademarks. is deleted and replaced with:
//
// 6. Trademarks. This License does not grant permission to use the trade
//    names, trademarks, service marks, or product names of the Licensor
//    and its affiliates, except as required to comply with Section 4(c) of
//    the License and to reproduce the content of the NOTICE file.
//
// You may obtain a copy of the Apache License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the Apache License with the above modification is
// distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
// KIND, either express or implied. See the Apache License for the specific
// language governing permissions and limitations under the Apache License.
//
#ifndef PXR_IMAGING_HD_ST_GLSL_PROGRAM_H
#define PXR_IMAGING_HD_ST_GLSL_PROGRAM_H

#include "pxr/pxr.h"
#include "pxr/imaging/hd/version.h"
#include "pxr/imaging/hdSt/api.h"
#include "pxr/imaging/hdSt/resourceGL.h"
#include "pxr/imaging/hgi/shaderProgram.h"
#include "pxr/imaging/hgi/enums.h"

PXR_NAMESPACE_OPEN_SCOPE

class HdStResourceRegistry;
using HdStGLSLProgramSharedPtr = std::shared_ptr<class HdStGLSLProgram>;

using HgiShaderProgramHandle = HgiHandle<class HgiShaderProgram>;

/// \class HdStGLSLProgram
///
/// An instance of a glsl program.
///
class HdStGLSLProgram final
{
public:
    typedef size_t ID;

    HDST_API
    HdStGLSLProgram(TfToken const &role, HdStResourceRegistry*const registry);
    HDST_API
    ~HdStGLSLProgram();

    /// Returns the hash value of the program for \a sourceFile
    HDST_API
    static ID ComputeHash(TfToken const & sourceFile);

    /// Compile shader source for a shader stage.
    HDST_API
    bool CompileShader(HgiShaderStage stage, std::string const & source);

    /// Link the compiled shaders together.
    HDST_API
    bool Link();

    /// Validate if this program is a valid progam in the current context.
    HDST_API
    bool Validate() const;

    /// Returns HdResource of the program object.
    HdStResourceGL const &GetProgram() const { return _programResource; }

    /// Returns HdResource of the global uniform buffer object for this program.
    HdStResourceGL const &GetGlobalUniformBuffer() const {
        return _uniformBuffer;
    }

    /// Convenience method to get a shared compute shader program
    HDST_API
    static HdStGLSLProgramSharedPtr GetComputeProgram(
        TfToken const &shaderToken,
        HdStResourceRegistry *resourceRegistry);
    
    HDST_API
    static HdStGLSLProgramSharedPtr GetComputeProgram(
        TfToken const &shaderFileName,
        TfToken const &shaderToken,
        HdStResourceRegistry *resourceRegistry);

private:
    HdStResourceRegistry *const _registry;
    HdStResourceGL _programResource;
    HdStResourceGL _uniformBuffer;

    HgiShaderProgramDesc _programDesc;
    HgiShaderProgramHandle _program;

    // An identifier for uniquely identifying the program, for debugging
    // purposes - programs that fail to compile for one reason or another
    // will get deleted, and their GL program IDs reused, so we can't use
    // that to identify it uniquely
    size_t _debugID;
};


PXR_NAMESPACE_CLOSE_SCOPE

#endif  // PXR_IMAGING_HD_ST_GLSL_PROGRAM_H
