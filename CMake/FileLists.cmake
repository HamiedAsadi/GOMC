set(sources 
   src/BlockOutput.cpp
   src/BondAdjacencyList.cpp
   src/BoxDimensions.cpp
   src/BoxDimensionsNonOrth.cpp
   src/CBMC.cpp
   src/CellList.cpp
   src/ConfigSetup.cpp
   src/ConsoleOutput.cpp
   src/Coordinates.cpp
   src/CPUSide.cpp
   src/CalculateEnergy.cpp
   src/CheckpointOutput.cpp
   src/CheckpointSetup.cpp
   src/DCDlib.cpp
   src/ExtendedSystemOutput.cpp
   src/EnPartCntSampleOutput.cpp
   src/ExtendedSystem.cpp
   src/Ewald.cpp
   src/EwaldCached.cpp
   src/FFConst.cpp
   src/FFDihedrals.cpp
   src/FFParticle.cpp
   src/FFSetup.cpp
   src/Forcefield.cpp
   src/FreeEnergyOutput.cpp
   src/Geometry.cpp
   src/HistOutput.cpp
   src/InputFileReader.cpp
   src/Main.cpp
   src/MoleculeKind.cpp
   src/MoleculeLookup.cpp
   src/Molecules.cpp
   src/MolSetup.cpp
   src/MoveSettings.cpp
   src/NoEwald.cpp
   src/OutConst.cpp
   src/OutputVars.cpp
   src/ParallelTemperingPreprocessor.cpp
   src/ParallelTemperingUtilities.cpp
   src/PDBSetup.cpp
   src/PDBOutput.cpp
   src/PRNGSetup.cpp
   src/PSFOutput.cpp
   src/Random123Wrapper.cpp
   src/Reader.cpp
   src/Simulation.cpp
   src/StaticVals.cpp
   src/System.cpp
   src/cbmc/DCCrankShaftAng.cpp
   src/cbmc/DCCrankShaftDih.cpp
   src/cbmc/DCCyclic.cpp
   src/cbmc/DCGraph.cpp
   src/cbmc/DCFreeCycle.cpp
   src/cbmc/DCFreeHedron.cpp
   src/cbmc/DCFreeHedronSeed.cpp
   src/cbmc/DCFreeCycleSeed.cpp
   src/cbmc/DCLinkedHedron.cpp
   src/cbmc/DCLinkedCycle.cpp
   src/cbmc/DCHedron.cpp
   src/cbmc/DCHedronCycle.cpp
   src/cbmc/DCLinear.cpp
   src/cbmc/DCOnSphere.cpp
   src/cbmc/DCRotateCOM.cpp
   src/cbmc/DCRotateOnAtom.cpp
   src/cbmc/DCSingle.cpp
   src/cbmc/TrialMol.cpp)

set(headers
   src/BlockOutput.h
   src/BondAdjacencyList.h
   src/BoxDimensions.h
   src/BoxDimensionsNonOrth.h
   src/CalculateEnergy.h
   src/CBMC.h
   src/CellList.h
   src/CheckpointOutput.h
   src/CheckpointSetup.h
   src/Clock.h
   src/COM.h
   src/ConfigSetup.h
   src/ConsoleOutput.h
   src/ConstField.h
   src/Coordinates.h
   src/CoordinateSetup.h
   src/CPUSide.h
   src/DCDlib.h
   src/ExtendedSystemOutput.h
   src/EnergyTypes.h
   src/EnPartCntSampleOutput.h
   src/EnsemblePreprocessor.h
   src/ExtendedSystem.h
   src/Ewald.h
   src/EwaldCached.h  
   src/FFAngles.h
   src/FFBonds.h
   src/FFConst.h
   src/FFDihedrals.h
   src/FFExp6.h
   src/FFParticle.h
   src/FFSetup.h
   src/FFShift.h
   src/FFSwitch.h
   src/FFSwitchMartini.h
   src/FixedWidthReader.h
   src/Forcefield.h
   src/FreeEnergyOutput.h
   src/FxdWidthWrtr.h
   src/Geometry.h
   src/GOMCEventsProfile.h
   src/GOMCEventsProfileDef.h
   src/HistOutput.h
   src/InputAbstracts.h
   src/InputFileReader.h
   src/MersenneTwister.h
   src/MoleculeKind.h
   src/MoleculeLookup.h
   src/Molecules.h
   src/MolPick.h
   src/MolSetup.h
   src/MoveConst.h
   src/MoveSettings.h
   src/NoEwald.h
   src/OutConst.h
   src/OutputAbstracts.h
   src/OutputVars.h
   src/ParallelTemperingPreprocessor.h
   src/ParallelTemperingUtilities.h
   src/PDBConst.h
   src/PDBOutput.h
   src/PDBSetup.h
   src/PRNG.h
   src/PRNGSetup.h
   src/PSFOutput.h
   src/Random123Wrapper.h
   src/Reader.h
   src/SeedReader.h
   src/Setup.h
   src/SimEventFrequency.h
   src/Simulation.h
   src/StaticVals.h
   src/SubdividedArray.h
   src/System.h
   src/TransformMatrix.h
   src/Velocity.h
   src/Writer.h
   src/XYZArray.h
   src/cbmc/DCComponent.h
   src/cbmc/DCCrankShaftAng.h
   src/cbmc/DCCrankShaftDih.h
   src/cbmc/DCCyclic.h
   src/cbmc/DCData.h
   src/cbmc/DCFreeCycle.h
   src/cbmc/DCFreeHedron.h
   src/cbmc/DCFreeHedronSeed.h
   src/cbmc/DCFreeCycleSeed.h
   src/cbmc/DCLinkedHedron.h
   src/cbmc/DCLinkedCycle.h
   src/cbmc/DCGraph.h
   src/cbmc/DCHedron.h
   src/cbmc/DCHedronCycle.h
   src/cbmc/DCLinear.h
   src/cbmc/DCOnSphere.h
   src/cbmc/DCRotateCOM.h
   src/cbmc/DCRotateOnAtom.h
   src/cbmc/DCSingle.h
   src/cbmc/TrialMol.h
   src/moves/CFCMC.h
   src/moves/CrankShaft.h
   src/moves/IntraMoleculeExchange1.h
   src/moves/IntraMoleculeExchange2.h
   src/moves/IntraMoleculeExchange3.h
   src/moves/IntraSwap.h
   src/moves/MoleculeExchange1.h
   src/moves/MoleculeExchange2.h
   src/moves/MoleculeExchange3.h
   src/moves/MoleculeTransfer.h
   src/moves/MoveBase.h
   src/moves/MultiParticle.h
   src/moves/MultiParticleBrownianMotion.h
   src/moves/Regrowth.h
   src/moves/Rotation.h
   src/moves/TargetedSwap.h
   src/moves/Translate.h
   src/moves/VolumeTransfer.h)

set(libHeaders
   lib/AlphaNum.h
   lib/BasicTypes.h
   lib/BitLib.h
   lib/Endian.h
   lib/GeomLib.h
   lib/Lambda.h
   lib/NumLib.h
   lib/StrLib.h
   lib/StrStrmLib.h
   lib/VectorLib.h
   lib/CircuitFinder.h
   lib/FloydWarshallCycle.h)

set(libSources
    lib/AlphaNum.cpp
    lib/CircuitFinder.cpp
    lib/FloydWarshallCycle.cpp)

set(cudaHeaders
    src/GPU/ConstantDefinitionsCUDAKernel.cuh
    src/GPU/CalculateMinImageCUDAKernel.cuh
    src/GPU/CalculateEnergyCUDAKernel.cuh
    src/GPU/CalculateForceCUDAKernel.cuh
    src/GPU/CalculateEwaldCUDAKernel.cuh
    src/GPU/CUDAMemoryManager.cuh
    src/GPU/TransformParticlesCUDAKernel.cuh
    src/GPU/VariablesCUDA.cuh)

set(cudaSources
    src/GPU/CalculateEnergyCUDAKernel.cu
    src/GPU/CalculateForceCUDAKernel.cu
    src/GPU/CalculateEwaldCUDAKernel.cu
    src/GPU/ConstantDefinitionsCUDAKernel.cu
    src/GPU/CUDAMemoryManager.cu
    src/GPU/TransformParticlesCUDAKernel.cu)

source_group("Header Files" FILES ${headers})
source_group("Lib Headers" FILES ${libHeaders})
source_group("CUDA Header Files" FILES ${cudaHeaders})
source_group("CUDA Source Files" FILES ${cudaSources})
