/*
 * Copyright 2020 The TensorFlow Runtime Authors
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

//===- types.h --------------------------------------------------*- C++ -*-===//
//
// This file declares types for the 'corert' dialect.
//
//===----------------------------------------------------------------------===//

#ifndef TF_RUNTIME_INCLUDE_TFRT_CORE_RUNTIME_OPDEFS_TYPES_H_
#define TF_RUNTIME_INCLUDE_TFRT_CORE_RUNTIME_OPDEFS_TYPES_H_

#include "mlir/IR/Types.h"

namespace tfrt {
namespace corert {

namespace CoreRTTypes {

enum Kind {
  kString = mlir::Type::FIRST_PRIVATE_EXPERIMENTAL_1_TYPE,
};

}  // namespace CoreRTTypes

class StringType : public mlir::Type::TypeBase<StringType, mlir::Type> {
 public:
  using Base::Base;

  static StringType get(mlir::MLIRContext *context) {
    return Base::get(context, CoreRTTypes::kString);
  }

  static bool kindof(unsigned kind) { return kind == CoreRTTypes::kString; }
};

}  // namespace corert
}  // namespace tfrt

#endif  // TF_RUNTIME_INCLUDE_TFRT_CORE_RUNTIME_OPDEFS_TYPES_H_
