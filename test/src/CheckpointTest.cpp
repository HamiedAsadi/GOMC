#include <gtest/gtest.h>
#include "PDBSetup.h"
#include "MolSetup.h"
#include "BondAdjacencyList.h"
#include "ConfigSetup.h"
#include "FFSetup.h"        //For geometry kinds
#include "FFConst.h"
#include "Reader.h"
#include "InputFileReader.h"
#include "Simulation.h"
#include<unistd.h> 
#include "MoveSettings.h"


TEST(CheckpointTest, Check_PEN_HEX) {

    ulong base_runsteps, Continued_runsteps;
    ulong Continued_true_step;
#if !GOMC_CUDA
    int result = chdir("./test/input/Systems/PEN_HEX/Base/");
    if (result){
        std::cout << "System call failed!" << std::endl;
        exit(1);
    }
    Simulation base("in.conf");
    base.RunSimulation();
    result = chdir("../Continued");
    if (result){
        std::cout << "System call failed!" << std::endl;
        exit(1);
    }
    Simulation Continued("in.conf");
    result = chdir("../SingleRun");
    if (result){
        std::cout << "System call failed!" << std::endl;
        exit(1);
    }
    Simulation SingleRun("in100.conf");
    SingleRun.RunSimulation();

    MoleculeLookup & Continued_ml = Continued.GetMolLookup();
    MoleculeLookup & SingleRun_ml = SingleRun.GetMolLookup();
    MoveSettings & Continued_ms = Continued.GetMoveSettings();
    MoveSettings & SingleRun_ms = SingleRun.GetMoveSettings();
    Coordinates & Continued_coords = Continued.GetCoordinates();
    Coordinates & SingleRun_coords = SingleRun.GetCoordinates();

    EXPECT_EQ(Continued_ml.operator==(SingleRun_ml), true);
    EXPECT_EQ(Continued_ms.operator==(SingleRun_ms), true);
    EXPECT_EQ(Continued_coords.operator==(SingleRun_coords), true);

    result = chdir("../../../../..");
    if (result){
        std::cout << "System call failed!" << std::endl;
        exit(1);
    } 
    result = chdir("./test/input/Systems/PEN_HEX");
    if (result){
        std::cout << "System call failed!" << std::endl;
        exit(1);
    }
    result = system("exec rm -r ./Base/Base_*");
    if (result){
        std::cout << "System call failed!" << std::endl;
        exit(1);
    }
    result = system("exec rm -r ./Continued/Continued_*");
    if (result){
        std::cout << "System call failed!" << std::endl;
        exit(1);
    }
    result = system("exec rm -r ./SingleRun/SingleRun_*");
    if (result){
        std::cout << "System call failed!" << std::endl;
        exit(1);
    }
    result = chdir("../../../..");
    if (result){
        std::cout << "System call failed!" << std::endl;
        exit(1);
    }
#endif
}

TEST(CheckpointTest, Check_BPTI_TIP3) {

    ulong base_runsteps, Continued_runsteps;
    ulong Continued_true_step;
#if !GOMC_CUDA
    int result = chdir("./test/input/Systems/BPTI_TIP3/Base/");
    if (result){
        std::cout << "System call failed!" << std::endl;
        exit(1);
    }
    Simulation base("in.conf");
    base.RunSimulation();
    result = chdir("../Continued");
    if (result){
        std::cout << "System call failed!" << std::endl;
        exit(1);
    }
    Simulation Continued("in.conf");
    result = chdir("../SingleRun");
    if (result){
        std::cout << "System call failed!" << std::endl;
        exit(1);
    }
    Simulation SingleRun("in100.conf");
    SingleRun.RunSimulation();

    MoleculeLookup & Continued_ml = Continued.GetMolLookup();
    MoleculeLookup & SingleRun_ml = SingleRun.GetMolLookup();
    MoveSettings & Continued_ms = Continued.GetMoveSettings();
    MoveSettings & SingleRun_ms = SingleRun.GetMoveSettings();
    Coordinates & Continued_coords = Continued.GetCoordinates();
    Coordinates & SingleRun_coords = SingleRun.GetCoordinates();
    Velocity & Continued_velocs = Continued.GetVelocities();
    Velocity & SingleRun_velocs = SingleRun.GetVelocities();
    ExtendedSystem & Continued_xsc = Continued.GetXSC();
    ExtendedSystem & SingleRun_xsc = SingleRun.GetXSC();

    EXPECT_EQ(Continued_ml.operator==(SingleRun_ml), true);
    EXPECT_EQ(Continued_ms.operator==(SingleRun_ms), true);
    EXPECT_EQ(Continued_coords.operator==(SingleRun_coords), true);
    EXPECT_EQ(Continued_velocs.operator==(SingleRun_velocs), true);
    EXPECT_EQ(Continued_xsc.operator==(SingleRun_xsc), true);

    EXPECT_EQ(Continued_ms.acceptPercent == SingleRun_ms.acceptPercent, true);
    EXPECT_EQ(Continued_ms.scale == SingleRun_ms.scale, true);
    EXPECT_EQ(Continued_ms.accepted == SingleRun_ms.accepted, true);
    EXPECT_EQ(Continued_ms.tries == SingleRun_ms.tries, true);
    EXPECT_EQ(Continued_ms.tempAccepted == SingleRun_ms.tempAccepted, true);
    EXPECT_EQ(Continued_ms.tempTries == SingleRun_ms.tempTries, true);
    EXPECT_EQ(Continued_ms.mp_r_max == SingleRun_ms.mp_r_max, true);
    EXPECT_EQ(Continued_ms.mp_t_max == SingleRun_ms.mp_t_max, true);
    EXPECT_EQ(Continued_ms.mp_accepted == SingleRun_ms.mp_accepted, true);
    EXPECT_EQ(Continued_ms.mp_tries == SingleRun_ms.mp_tries, true);
    EXPECT_EQ(Continued_ms.mp_interval_accepted == SingleRun_ms.mp_interval_accepted, true);
    EXPECT_EQ(Continued_ms.mp_interval_tries == SingleRun_ms.mp_interval_tries, true);


    result = chdir("../../../../..");
    if (result){
        std::cout << "System call failed!" << std::endl;
        exit(1);
    } 
    result = chdir("./test/input/Systems/BPTI_TIP3");
    if (result){
        std::cout << "System call failed!" << std::endl;
        exit(1);
    }
    result = system("exec rm -r ./Base/Base_*");
    if (result){
        std::cout << "System call failed!" << std::endl;
        exit(1);
    }
    result = system("exec rm -r ./Continued/Continued_*");
    if (result){
        std::cout << "System call failed!" << std::endl;
        exit(1);
    }
    result = system("exec rm -r ./SingleRun/SingleRun_*");
    if (result){
        std::cout << "System call failed!" << std::endl;
        exit(1);
    }
    result = chdir("../../../..");
    if (result){
        std::cout << "System call failed!" << std::endl;
        exit(1);
    }
#endif
}