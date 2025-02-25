//
// Copyright (c) 2021 The Khronos Group Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//    http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
#ifndef COMMON_H
#define COMMON_H

#include "harness/typeWrappers.h"
#include "utility.h"

#include <array>
#include <vector>

// Array of thread-specific kernels for each vector size.
using KernelMatrix = std::array<std::vector<cl_kernel>, VECTOR_SIZE_COUNT>;

// Array of programs for each vector size.
using Programs = std::array<clProgramWrapper, VECTOR_SIZE_COUNT>;

// Information to generate OpenCL kernels.
struct BuildKernelInfo
{
    // Number of kernels to build, one for each thread to avoid data races.
    cl_uint threadCount;

    KernelMatrix &kernels;

    Programs &programs;

    // Function, macro or symbol tested by the kernel.
    const char *nameInCode;

    // Whether to build with -cl-fast-relaxed-math.
    bool relaxedMode;
};

#endif /* COMMON_H */
