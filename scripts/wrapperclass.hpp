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

//## This file is typically used by extending: see e.g. time and duration

//# from 'macros.hpp' import make_spec_ref, wrapperSizeStaticAssert


//# if raw_type is not defined
//#     set raw_type = "Xr" + type
//# endif
//# if raw_input_type is not defined
//#     set raw_input_type = raw_type
//# endif

//## By default, assume these are "small" and should be passed by value
//# if input_param_type is not defined
//#     set input_param_type = type
//# endif

//# if object_instance_desc is not defined
//#     set object_instance_desc = "instance"
//# endif

//## Default to no comparisons
//# if comparison_operators is not defined
//#     set comparison_operators = {}
//# endif

//# block prefix scoped
//# endblock prefix

//# block comment_class scoped
//#     filter block_doxygen_comment
//! @brief /*% block comment_brief %*//*{ raw_type }*/ wrapper class/*% endblock comment_brief %*/
//!
//! /*{ make_spec_ref(raw_type) }*/
//!
//! @xrentity{/*{ raw_type }*/}
//#         if doc_group
//! @ingroup /*{ doc_group }*/
//#         endif
//#     endfilter
//# endblock comment_class
/*% block compound_type %*/class/*% endblock%*/ /*{ type }*/ /*% block parent_decl%*//*% endblock %*/ {
   public:

//# block member_types
//# endblock member_types

//# block constructors_begin
    /*!
     * @name Constructors, assignment, and conversions
     * @{
     */
//# endblock constructors_begin

//# block constructors scoped
//# endblock constructors

//# block constructors_end
    //! @}
//# endblock constructors_end

//# block validity
//# endblock validity

//# filter block_doxygen_comment
    //! @name Raw /*{ raw_type }*/ manipulation
    //! @{
//# endfilter


//# block raw_methods

//#     block method_get

    //! Gets the raw /*{ raw_type }*/ value.
    OPENXR_HPP_CONSTEXPR /*{ raw_type }*/ get() const noexcept {
//#         block method_get_body scoped
#error "Must override block method_get_body"
//#         endblock method_get_body
    }
//#     endblock method_get


//#     block method_put
//#         filter block_doxygen_comment
    //! @brief Clears this /*{ object_instance_desc }*/, then returns the address of the raw /*{ raw_type }*/ value,
    //! for use in creation/assignment.
//#         endfilter
    /*{ raw_type }*/ *put(bool clear = true) noexcept {
//#         block method_put_body scoped
#error "Must override block method_put_body"
//#         endblock method_put_body
    }
//#     endblock method_put

//# endblock raw_methods
    //! @}

//# block extra_methods scoped
//# endblock extra_methods

   private:
//# block private
//# endblock private
};

//# block size_assert
/*{ wrapperSizeStaticAssert(raw_type, type) }*/

//# endblock size_assert

//# block free_get scoped

//#     filter block_doxygen_comment
//! @brief Free function for getting the raw /*{ raw_type }*/ from an /*{type}*/ /*{ object_instance_desc }*/.
//!
//! Should not need explicit namespace qualification (found via ADL).
//! @see /*{type}*/::get()
//! @relates /*{type}*/
//#     endfilter
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE /*{ raw_type }*/ get(/*{input_param_type}*/ v) noexcept { return v.get(); }
//# endblock free_get

//# block free_put scoped
//#     filter block_doxygen_comment
//! @brief Free function for clearing (by default) and getting the address of the raw /*{ raw_type }*/ from an /*{type}*/ /*{ object_instance_desc }*/.
//!
//! Should not need explicit namespace qualification (found via ADL).
//! @see /*{type}*/::put( )
//! @relates /*{type}*/
//#     endfilter
static OPENXR_HPP_INLINE /*{ raw_type }*/ *put(/*{type}*/ &v, bool clear = true) noexcept { return v.put(clear); }
//# endblock free_put

//# block comparisons scoped

//#     block compare_self
//#         for op in comparison_operators
//! @brief `/*{op}*/` comparison between /*{type}*/ /*{ object_instance_desc + "s" }*/.
//! @relates /*{type}*/
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator/*{- op -}*/(/*{input_param_type}*/ lhs, /*{input_param_type}*/ rhs) noexcept {
    return lhs.get() /*{- op -}*/ rhs.get();
}
//#         endfor
//#     endblock compare_self

//#     block compare_raw
//#         for op in comparison_operators
//! @brief `/*{op}*/` comparison between /*{type}*/ and raw /*{raw_type}*/.
//! @relates /*{type}*/
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator/*{- op -}*/(/*{input_param_type}*/ lhs, /*{raw_input_type}*/ rhs) noexcept {
    return lhs.get() /*{- op -}*/ rhs;
}
//! @brief `/*{op}*/` comparison between raw /*{raw_type}*/ and /*{type}*/.
//! @relates /*{type}*/
OPENXR_HPP_CONSTEXPR OPENXR_HPP_INLINE bool operator/*{- op -}*/(/*{raw_input_type}*/ lhs, /*{input_param_type}*/ rhs) noexcept {
    return lhs /*{- op -}*/ rhs.get();
}
//#         endfor
//#     endblock compare_raw

//# endblock comparisons

//# block extra_free_functions
//# endblock extra_free_functions

//# block suffix
//# endblock suffix
