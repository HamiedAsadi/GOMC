/*******************************************************************************
GPU OPTIMIZED MONTE CARLO (GOMC) 2.70
Copyright (C) 2018  GOMC Group
A copy of the GNU General Public License can be found in the COPYRIGHT.txt
along with this program, also can be found at <http://www.gnu.org/licenses/>.
********************************************************************************/

#include <stdint.h>
#include "CheckpointSetup.h"

CheckpointSetup::CheckpointSetup(ulong & startStep,
                                ulong & trueStep,
                                MoleculeLookup & molLookup, 
                                MoveSettings & moveSettings,
                                Molecules & mol,
                                PRNG & prng,
                                Random123Wrapper & r123,
                                Setup & set) :
  molLookupRef(molLookup), moveSetRef(moveSettings), molRef(mol), prngRef(prng),
  r123Ref(r123), startStepRef(startStep), trueStepRef(trueStep),
  molSetRef(set.mol), ffSetupRef(set.ff), pdbAtomsRef(set.pdb.atoms),
  startIdxMolecules(set.mol.molVars.startIdxMolecules)
{
  std::string file = set.config.in.files.checkpoint.name[0];
#if GOMC_LIB_MPI
  filename = sys.ms->replicaInputDirectoryPath + file;
#else
  filename = file;
#endif
}

CheckpointSetup::~CheckpointSetup(){}


std::string CheckpointSetup::getFileName(){
  return filename;
}

void CheckpointSetup::loadCheckpointFile(){
  // create and open a character archive for intput
  std::ifstream ifs(filename);
  if (!ifs.is_open()){
    fprintf(stderr, "Error opening checkpoint input file %s\n",
            filename.c_str());
    exit(EXIT_FAILURE);
  }
  cereal::BinaryInputArchive ia(ifs);
  ia >> chkObj;
  SetCheckpointData();
  std::cout << "Checkpoint loaded from " << filename << std::endl;
}

void CheckpointSetup::InitOver(){
  SetMolecules();
}

void CheckpointSetup::SetCheckpointData(){
  SetStepNumber();
  SetTrueStepNumber();
  SetMoveSettings();
  SetPRNGVariables();
  SetR123Variables();
  SetMolecules();
<<<<<<< c6c7bdcd039f4cb264573bee7434d2caef004f85
  SetMoleculeLookup();
=======
  SetMoleculeIndices();
>>>>>>> Molecule Lookup is now an object of vectors instead of arrays
  SetMoleculeSetup();
  SetPDBSetupAtoms();
}

#if GOMC_LIB_MPI
void CheckpointSetup::SetCheckpointData   (bool & parallelTemperingIsEnabled,
                                          PRNG & prngPT){
  SetStepNumber();
  SetTrueStepNumber();
  SetMoveSettings();
  SetPRNGVariables();
  SetR123Variables();
  SetMolecules();
<<<<<<< c6c7bdcd039f4cb264573bee7434d2caef004f85
  SetMoleculeLookup();
=======
  SetMoleculeIndices();
>>>>>>> Molecule Lookup is now an object of vectors instead of arrays
  SetMoleculeSetup();
  SetPDBSetupAtoms();
  SetParallelTemperingWasEnabled();
  if(parallelTemperingIsEnabled && parallelTemperingWasEnabled)
    SetPRNGVariablesPT();
}
#endif

void CheckpointSetup::SetStepNumber()
{
  startStepRef = chkObj.stepNumber;
}

void CheckpointSetup::SetTrueStepNumber()
{
  printf("%-40s %-lu \n", "Info: Loading true step from checkpoint", chkObj.trueStepNumber);
  trueStepRef = chkObj.trueStepNumber;
}

void CheckpointSetup::SetMoveSettings()
{
  moveSetRef.scale = chkObj.scaleVec;
  moveSetRef.acceptPercent = chkObj.acceptPercentVec;
  moveSetRef.accepted = chkObj.acceptedVec;
  moveSetRef.tries = chkObj.triesVec;
  moveSetRef.tempAccepted = chkObj.tempAcceptedVec;
  moveSetRef.tempTries = chkObj.tempTriesVec;
  moveSetRef.mp_tries = chkObj.mp_triesVec;
  moveSetRef.mp_accepted = chkObj.mp_acceptedVec;
  moveSetRef.mp_interval_accepted = chkObj.mp_interval_acceptedVec;
  moveSetRef.mp_interval_tries = chkObj.mp_interval_triesVec;
  moveSetRef.mp_t_max = chkObj.mp_t_maxVec;
  moveSetRef.mp_r_max = chkObj.mp_r_maxVec;
  for (int b = 0; b < BOXES_WITH_U_NB; ++b)
    moveSetRef.isSingleMoveAccepted[b] = chkObj.isSingleMoveAccepted[b];
}

void CheckpointSetup::SetPRNGVariables()
{
  prngRef.GetGenerator()->load(chkObj.saveArray);
  prngRef.GetGenerator()->pNext = prngRef.GetGenerator()->state + chkObj.seedLocation;
  prngRef.GetGenerator()->left = chkObj.seedLeft;
  prngRef.GetGenerator()->seedValue = chkObj.seedValue;
}

void CheckpointSetup::SetR123Variables()
{
  r123Ref.SetRandomSeed(chkObj.seedValue);
}

void CheckpointSetup::SetMolecules()
{
  molRef.restartOrderedStart = new uint [chkObj.originalMolSetup.molVars.moleculeIteration + 1];
  /* If new run, originalStart & originalKIndex and start & kIndex are identical */
  molRef.restartOrderedStart = vect::TransferInto<uint>(molRef.restartOrderedStart, chkObj.restartedStartVec);
}

void CheckpointSetup::SetMoleculeLookup(){
  /* Original Mol Indices are for constant trajectory output from start to finish of a single run*/
<<<<<<< c6c7bdcd039f4cb264573bee7434d2caef004f85
  molLookupRef = chkObj.originalMoleculeLookup;
}

void CheckpointSetup::SetMoleculeSetup(){
  molSetRef = chkObj.originalMolSetup;
  molSetRef.AssignKinds(molSetRef.molVars, ffSetupRef);
}

void CheckpointSetup::SetPDBSetupAtoms(){
  uint p, d, trajectoryI, dataI, placementStart, placementEnd, dataStart, dataEnd;
  for (int mol = 0; mol < chkObj.originalMolSetup.molVars.moleculeIteration; mol++){
    trajectoryI = chkObj.originalMoleculeLookup.restartMoleculeIndices[mol];
    dataI = mol;
    //Loop through particles in mol.
    GetOriginalRangeStartStop(placementStart, placementEnd, trajectoryI);
    GetRestartRangeStartStop(dataStart, dataEnd, dataI);
    for (p = placementStart, d = dataStart; p < placementEnd; ++p, ++d) {
      chkObj.originalAtoms.x[p] = pdbAtomsRef.x[d];
      chkObj.originalAtoms.y[p] = pdbAtomsRef.y[d];
      chkObj.originalAtoms.z[p] = pdbAtomsRef.z[d];
      chkObj.originalAtoms.beta[p] = pdbAtomsRef.beta[d];
      chkObj.originalAtoms.box[p] = pdbAtomsRef.box[d];
    }
  }
  // Should do a default assignment of the vectors and primitives.
  pdbAtomsRef = chkObj.originalAtoms;
=======
  molLookupRef.restartMoleculeIndices = chkObj.restartMoleculeIndicesVec;
>>>>>>> Molecule Lookup is now an object of vectors instead of arrays
}

void CheckpointSetup::SetMoleculeSetup(){
  molSetRef = chkObj.originalMolSetup;
  molSetRef.AssignKinds(molSetRef.molVars, ffSetupRef);
}

void CheckpointSetup::SetPDBSetupAtoms(){
  uint p, d, trajectoryI, dataI, placementStart, placementEnd, dataStart, dataEnd;
  for (int mol = 0; mol < chkObj.originalMolSetup.molVars.moleculeIteration; mol++){
    trajectoryI = chkObj.restartMoleculeIndicesVec[mol];
    dataI = mol;
    //Loop through particles in mol.
    GetOriginalRangeStartStop(placementStart, placementEnd, trajectoryI);
    GetRangeStartStop(dataStart, dataEnd, dataI);
    for (p = placementStart, d = dataStart; p < placementEnd; ++p, ++d) {
      chkObj.originalAtoms.x[p] = pdbAtomsRef.x[d];
      chkObj.originalAtoms.y[p] = pdbAtomsRef.y[d];
      chkObj.originalAtoms.z[p] = pdbAtomsRef.z[d];
      chkObj.originalAtoms.beta[p] = pdbAtomsRef.beta[d];
      chkObj.originalAtoms.box[p] = pdbAtomsRef.box[d];
    }
  }
  // Should do a default assignment of the vectors and primitives.
  pdbAtomsRef = chkObj.originalAtoms;
}


#if GOMC_LIB_MPI
bool CheckpointSetup::SetParallelTemperingWasEnabled()
{
  parallelTemperingWasEnabled = (bool)chkObj.parallelTemperingEnabled;
}

void CheckpointSetup::SetPRNGVariablesPT(PRNG & prng)
{
  prngPT.GetGenerator()->load(chkObj.saveArrayPT);
  prngPT.GetGenerator()->pNext = prngPT.GetGenerator()->state + chkObj.seedLocationPT;
  prngPT.GetGenerator()->left = chkObj.seedLeftPT;
  prngPT.GetGenerator()->seedValue = chkObj.seedValuePT;
}
#endif

void CheckpointSetup::GetRestartRangeStartStop(uint & _start, uint & stop, const uint m) const
{
  _start = chkObj.restartedStartVec[m];
  stop = chkObj.restartedStartVec[m + 1];
}

void CheckpointSetup::GetOriginalRangeStartStop(uint & _start, uint & stop, const uint m) const
{
  _start = chkObj.originalStartVec[m];
  stop = chkObj.originalStartVec[m + 1];
}