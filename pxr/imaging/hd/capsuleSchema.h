//
// Copyright 2022 Pixar
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
////////////////////////////////////////////////////////////////////////
// This file is generated by a script.  Do not edit directly.  Edit the
// schema.template.h file to make changes.

#ifndef PXR_IMAGING_HD_CAPSULE_SCHEMA_H
#define PXR_IMAGING_HD_CAPSULE_SCHEMA_H

#include "pxr/imaging/hd/api.h"

#include "pxr/imaging/hd/schema.h" 

PXR_NAMESPACE_OPEN_SCOPE

//-----------------------------------------------------------------------------

#define HDCAPSULE_SCHEMA_TOKENS \
    (capsule) \
    (height) \
    (radius) \
    (axis) \
    (X) \
    (Y) \
    (Z) \

TF_DECLARE_PUBLIC_TOKENS(HdCapsuleSchemaTokens, HD_API,
    HDCAPSULE_SCHEMA_TOKENS);

//-----------------------------------------------------------------------------

class HdCapsuleSchema : public HdSchema
{
public:
    HdCapsuleSchema(HdContainerDataSourceHandle container)
    : HdSchema(container) {}

    //ACCESSORS

    HD_API
    HdDoubleDataSourceHandle GetHeight();
    HD_API
    HdDoubleDataSourceHandle GetRadius();
    HD_API
    HdTokenDataSourceHandle GetAxis();

    // RETRIEVING AND CONSTRUCTING

    /// Builds a container data source which includes the provided child data
    /// sources. Parameters with nullptr values are excluded. This is a
    /// low-level interface. For cases in which it's desired to define
    /// the container with a sparse set of child fields, the Builder class
    /// is often more convenient and readable.
    HD_API
    static HdContainerDataSourceHandle
    BuildRetained(
        const HdDoubleDataSourceHandle &height,
        const HdDoubleDataSourceHandle &radius,
        const HdTokenDataSourceHandle &axis
    );

    /// \class HdCapsuleSchema::Builder
    /// 
    /// Utility class for setting sparse sets of child data source fields to be
    /// filled as arguments into BuildRetained. Because all setter methods
    /// return a reference to the instance, this can be used in the "builder
    /// pattern" form.
    class Builder
    {
    public:
        HD_API
        Builder &SetHeight(
            const HdDoubleDataSourceHandle &height);
        HD_API
        Builder &SetRadius(
            const HdDoubleDataSourceHandle &radius);
        HD_API
        Builder &SetAxis(
            const HdTokenDataSourceHandle &axis);

        /// Returns a container data source containing the members set thus far.
        HD_API
        HdContainerDataSourceHandle Build();

    private:
        HdDoubleDataSourceHandle _height;
        HdDoubleDataSourceHandle _radius;
        HdTokenDataSourceHandle _axis;
    };

    /// Retrieves a container data source with the schema's default name token
    /// "capsule" from the parent container and constructs a
    /// HdCapsuleSchema instance.
    /// Because the requested container data source may not exist, the result
    /// should be checked with IsDefined() or a bool comparison before use.
    HD_API
    static HdCapsuleSchema GetFromParent(
        const HdContainerDataSourceHandle &fromParentContainer);

    /// Returns an HdDataSourceLocator (relative to the prim-level data source)
    /// where the container representing this schema is found by default.
    HD_API
    static const HdDataSourceLocator &GetDefaultLocator();

};

PXR_NAMESPACE_CLOSE_SCOPE

#endif
