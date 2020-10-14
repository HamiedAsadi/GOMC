/*******************************************************************************
GPU OPTIMIZED MONTE CARLO (GOMC) 2.70
Copyright (C) 2018  GOMC Group
A copy of the GNU General Public License can be found in the COPYRIGHT.txt
along with this program, also can be found at <http://www.gnu.org/licenses/>.
********************************************************************************/
#pragma once
#ifdef GOMC_CUDA
#include <cuda.h>
#include <cuda_runtime.h>
#include <unordered_map>
#include <iostream>

#define CUMALLOC(address,size) CUDAMemoryManager::mallocMemory(address,size,#address)
#define CUFREE(address) CUDAMemoryManager::freeMemory(address,#address)

class CUDAMemoryManager
{
public:
  static cudaError_t mallocMemory(void **address, unsigned int size, std::string var_name);
  static cudaError_t freeMemory(void *address, std::string var_name);
  static bool isFreed();

private:
  static long long totalAllocatedBytes;
  static std::unordered_map<void *, std::pair<unsigned int, std::string> > allocatedPointers;
};

#endif
