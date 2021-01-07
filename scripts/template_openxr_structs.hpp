//## Copyright (c) 2017-2020 The Khronos Group Inc.
//## Copyright (c) 2019-2020 Collabora, Ltd.
//##
//## Licensed under the Apache License, Version 2.0 (the "License");
//## you may not use this file except in compliance with the License.
//## You may obtain a copy of the License at
//##
//##     http://www.apache.org/licenses/LICENSE-2.0
//##
//## Unless required by applicable law or agreed to in writing, software
//## distributed under the License is distributed on an "AS IS" BASIS,
//## WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//## See the License for the specific language governing permissions and
//## limitations under the License.
//##
//## ---- Exceptions to the Apache 2.0 License: ----
//##
//## As an exception, if you use this Software to generate code and portions of
//## this Software are embedded into the generated code as a result, you may
//## redistribute such product without providing attribution as would otherwise
//## be required by Sections 4(a), 4(b) and 4(d) of the License.
//##
//## In addition, if you combine or link code generated by this Software with
//## software that is licensed under the GPLv2 or the LGPL v2.0 or 2.1
//## ("`Combined Software`") and if a court of competent jurisdiction determines
//## that the patent provision (Section 3), the indemnity provision (Section 9)
//## or other Section of the License conflicts with the conditions of the
//## applicable GPL or LGPL license, you may retroactively and prospectively
//## choose to deem waived or otherwise exclude such Section(s) of the License,
//## but only in their entirety and only with respect to the Combined Software.

//# from 'macros.hpp' import wrapperSizeStaticAssert, make_spec_ref

//# include('file_header.hpp')
/**
 * @file
 * @brief C++ projections of OpenXR structure types.
 */

/*!
 * @defgroup structs Struct wrappers
 * @brief C++ projections of OpenXR structure types, with easier init but identical layout.
 */
/*!
 * @defgroup typedstructs Typed/Chainable struct wrappers
 * @brief C++ projections of those OpenXR structure types with a `type` and `next` field.
 * @ingroup structs
 */
/*!
 * @defgroup abstracttypedstructs Abstract typed structs
 * @brief C++ projections of those OpenXR structure types with a `type` and `next` field,
 * but no specific type enum value of their own: these are the "base structs" in OpenXR.
 * @ingroup typedstructs
 */

// for strncpy_s
#ifndef __STDC_WANT_LIB_EXT1__
#define __STDC_WANT_LIB_EXT1__ 1
#endif
#include <string.h>

#include "openxr_enums.hpp"
#include "openxr_flags.hpp"
#include "openxr_version.hpp"
#include "openxr_time.hpp"
#include "openxr_atoms.hpp"
#include "openxr_handles.hpp"

#include <openxr/openxr.h>

#ifdef OPENXR_HPP_DOXYGEN
#include <openxr/openxr_platform.h>
#endif

namespace OPENXR_HPP_NAMESPACE {

using Bool32 = XrBool32;

namespace impl {

    class XR_MAY_ALIAS InputStructBase {
    protected:
        InputStructBase(StructureType type_,
                        const void* next_ = nullptr)
            : type(type_), next(next_) {}

    public:
        StructureType type;
        const void* next;
    };
    /*{ wrapperSizeStaticAssert('::XrBaseInStructure', 'InputStructBase') }*/

    class XR_MAY_ALIAS OutputStructBase {
    protected:
        OutputStructBase(StructureType type_, void* next_ = nullptr)
            : type(type_), next(next_) {}

    public:
        StructureType type;
        void* next;
    };
    /*{ wrapperSizeStaticAssert('::XrBaseOutStructure', 'OutputStructBase') }*/
}  // namespace impl

//# filter block_doxygen_comment
//! @brief Wrapper for XrEventDataBuffer
//!
//! /*{ make_spec_ref("XrEventDataBuffer") }*/
//!
//! @xrentity{XrEventDataBuffer}
//! @ingroup typedstructs
//# endfilter
struct XR_MAY_ALIAS EventDataBuffer : public impl::InputStructBase {
private:
    using Parent = impl::InputStructBase;

protected:
    EventDataBuffer(StructureType type_, const void* next_ = nullptr)
        : Parent(type_, next_), varying{} {}

public:
    //! Default constructor - use this one.
    EventDataBuffer() : Parent(StructureType::EventDataBuffer), varying{} {
        (void)varying;
    }
    //! @brief "Put" function for assigning as null then getting the address of the raw pointer to pass as function output parameter.
    XrEventDataBuffer* put(bool clear = true) noexcept {
        if (clear) {
            auto oldNext = next;
            *this = {};
            next = oldNext;
        }
        return reinterpret_cast<XrEventDataBuffer*>(this);
    }

    //! Gets a pointer to the underlying raw XrEventDataBuffer type.
    XrEventDataBuffer* get() noexcept {
        return reinterpret_cast<XrEventDataBuffer*>(this);
    }

    //! Gets a pointer to the underlying raw XrEventDataBuffer type.
    XrEventDataBuffer const* get() const noexcept {
        return reinterpret_cast<XrEventDataBuffer const*>(this);
    }

private:
    uint8_t varying[4000];
};
/*{ wrapperSizeStaticAssert('::XrEventDataBuffer', 'EventDataBuffer') }*/

//! @relates EventDataBuffer
OPENXR_HPP_INLINE XrEventDataBuffer* put(EventDataBuffer& v, bool clear = true) noexcept {
    return v.put(clear);
}

//# for struct in gen.api_structures if struct.name not in manually_projected

//#     include('struct.hpp')

//# endfor

}  // namespace OPENXR_HPP_NAMESPACE

//# include('file_footer.hpp')
