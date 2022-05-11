#ifndef CELLLIST_GPU_H
#define CELLLIST_GPU_H
#ifdef GOMC_CUDA

#include "VariablesCUDA.cuh"
#include "XYZArray.h"
#include "CalculateMinImageCUDAKernel.cuh"

__global__ void MapParticlesToCellKernel(int atomNumber,
                    double* gpu_x,
                    double* gpu_y,
                    double* gpu_z,                                
                    int* gpu_mapParticleToCell,
                    double *gpu_cellSize,
                    int *gpu_edgeCells,
                    int* gpu_nonOrth,
                    double *gpu_Invcell_x,
                    double *gpu_Invcell_y,
                    double *gpu_Invcell_z);

class CellListGPU {
  public:
    CellListGPU(VariablesCUDA * cv);
    void MapParticlesToCell(VariablesCUDA * cv,
                            XYZArray const &coords,
                            XYZArray const &axes);
    void CopyMapParticlesToCellToHost(
                                      XYZArray const &coords,
                                      std::vector<int> & host_mapParticleToCell);
    // new pair interaction calculation done on GPU
    int *gpu_cellVector, *gpu_mapParticleToCell, *gpu_cellStartIndex;
    // Fixed as long as volume doesnt change
    // Regenerate after volume moves.
    int *gpu_neighborList, *gpu_numberOfCells, *gpu_startOfBoxCellList;
    int *gpu_edgeCells;
    double *gpu_cellSize;
};

#endif
#endif