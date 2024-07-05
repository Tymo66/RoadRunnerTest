// RoadRunnerTest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <conio.h>
#include <ppl.h>
#include "rr/rrRoadRunner.h"
#include "rr/rrExecutableModel.h"

using namespace rr;

std::chrono::high_resolution_clock::time_point g_begin;
std::chrono::high_resolution_clock::time_point g_step;
std::chrono::high_resolution_clock::time_point g_nextStep;
void AddEvents(RoadRunner* pRoadRunner);
void RemoveEvents(RoadRunner* pRoadRunner);
void ClockStep(const std::string& cstrMsg);
void RunSingle(const std::string& crstrSbmlEuromix);
void RunParallel(const std::string& crstrSbmlEuromix);

static std::string getSBMLString() {
    return "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n"
        "<sbml xmlns=\"http://www.sbml.org/sbml/level3/version2/core\" level=\"3\" version=\"2\">\n"
        "  <model metaid=\"_case00001\" id=\"case00001\" name=\"case00001\" timeUnits=\"time\">\n"
        "    <listOfUnitDefinitions>\n"
        "      <unitDefinition id=\"volume\">\n"
        "        <listOfUnits>\n"
        "          <unit kind=\"litre\" exponent=\"1\" scale=\"0\" multiplier=\"1\"/>\n"
        "        </listOfUnits>\n"
        "      </unitDefinition>\n"
        "      <unitDefinition id=\"substance\">\n"
        "        <listOfUnits>\n"
        "          <unit kind=\"mole\" exponent=\"1\" scale=\"0\" multiplier=\"1\"/>\n"
        "        </listOfUnits>\n"
        "      </unitDefinition>\n"
        "      <unitDefinition id=\"time\">\n"
        "        <listOfUnits>\n"
        "          <unit kind=\"second\" exponent=\"1\" scale=\"0\" multiplier=\"1\"/>\n"
        "        </listOfUnits>\n"
        "      </unitDefinition>\n"
        "    </listOfUnitDefinitions>\n"
        "    <listOfCompartments>\n"
        "      <compartment id=\"compartment\" name=\"compartment\" spatialDimensions=\"3\" size=\"1\" units=\"volume\" constant=\"true\"/>\n"
        "    </listOfCompartments>\n"
        "    <listOfSpecies>\n"
        "      <species id=\"S1\" name=\"S1\" compartment=\"compartment\" initialAmount=\"0.00015\" substanceUnits=\"substance\" hasOnlySubstanceUnits=\"false\" boundaryCondition=\"false\" constant=\"false\"/>\n"
        "      <species id=\"S2\" name=\"S2\" compartment=\"compartment\" initialAmount=\"0\" substanceUnits=\"substance\" hasOnlySubstanceUnits=\"false\" boundaryCondition=\"false\" constant=\"false\"/>\n"
        "    </listOfSpecies>\n"
        "    <listOfParameters>\n"
        "      <parameter id=\"k1\" name=\"k1\" value=\"1\" constant=\"true\"/>\n"
        "    </listOfParameters>\n"
        "    <listOfReactions>\n"
        "      <reaction id=\"reaction1\" name=\"reaction1\" reversible=\"false\">\n"
        "        <listOfReactants>\n"
        "          <speciesReference species=\"S1\" stoichiometry=\"1\" constant=\"true\"/>\n"
        "        </listOfReactants>\n"
        "        <listOfProducts>\n"
        "          <speciesReference species=\"S2\" stoichiometry=\"1\" constant=\"true\"/>\n"
        "        </listOfProducts>\n"
        "        <kineticLaw>\n"
        "          <math xmlns=\"http://www.w3.org/1998/Math/MathML\">\n"
        "            <apply>\n"
        "              <times/>\n"
        "              <ci> compartment </ci>\n"
        "              <ci> k1 </ci>\n"
        "              <ci> S1 </ci>\n"
        "            </apply>\n"
        "          </math>\n"
        "        </kineticLaw>\n"
        "      </reaction>\n"
        "    </listOfReactions>\n"
        "  </model>\n"
        "</sbml>";
}

int main()
{
    // Recording the timestamp at the start of the code
    auto beg = std::chrono::high_resolution_clock::now();
    g_step = beg;
    g_nextStep = beg;

    // Loading SBML file
    std::ifstream sbmlFile("EuroMixGenericPbk_V1.sbml");
    std::stringstream ss;
    std::string line;
    while (std::getline(sbmlFile, line)) {
        ss << line;
    }
    auto sbmlEuroMix = ss.str();
    ClockStep("Loaded SBML file");

    //RunSingle(sbmlEuroMix);
    RunParallel(sbmlEuroMix);

    // Recording the timestamp at the start of the code
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds> (end - beg);
    std::cout << "Total elapsed Time: " << duration.count() << " (ms)" << std::endl;

    std::cout << "Type any key to exit ...";
    const int res = getch();

    return 0;
}

void RunSingle(const std::string& crstrSbmlEuromix) {

    RoadRunner roadRunner(crstrSbmlEuromix);
    ClockStep("Initialize RoadRunner with SBML file");

    AddEvents(&roadRunner);
    ClockStep("Add events");

    roadRunner.regenerateModel(true, true);
    ClockStep("Regenerate model");

    const ls::DoubleMatrix* cpResult = roadRunner.simulate(0, 240, 241);
    ClockStep("Simulate model");

    /*const unsigned rows = cpResult->numRows();
    const unsigned cols = cpResult->numCols();
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            std::cout << "Value [" << r << ", " << c << "] = " << (*cpResult)(r, c) << std::endl;
        }
    }*/
    std::cout << std::endl;
}


void RunParallel(const std::string& crstrSbmlEuromix) {

    concurrency::parallel_for(int(0), 10, [](int i) {

        //const string copy = crstrSbmlEuromix;

        RoadRunner roadRunner(getSBMLString());
        {
            std::stringstream sstr;
            sstr << "[Run " << i << "] " << "Initialize RoadRunner with SBML file";
            ClockStep(sstr.str());
        }

        AddEvents(&roadRunner);
        {
            std::stringstream sstr;
            sstr << "[Run " << i << "] " << "Add events";
            ClockStep(sstr.str());
        }
        /*
        roadRunner.regenerateModel(true, true);
        {
            std::stringstream sstr;
            sstr << "[Run " << i << "] " << "Regenerate model";
            ClockStep(sstr.str());
        }

        const ls::DoubleMatrix* cpResult = roadRunner.simulate(0, 240, 241);
        {
            std::stringstream sstr;
            sstr << "[Run " << i << "] " << "Simulate model";
            ClockStep(sstr.str());
        }*/
    });
}


void AddEvents(RoadRunner* pRoadRunner) {

    // add 10 events and event assignments
    const int nrEvents = 10;
    for (int i = 0; i < 10; ++i) {

        if (i == 0) {
            pRoadRunner->addEvent("ev_1", false, "time > 0", false);
        }
        else if (i == 1) {
            pRoadRunner->addEvent("ev_2", false, "time > 24", false);
        }
        else if (i == 2) {
            pRoadRunner->addEvent("ev_3", false, "time > 48", false);
        }
        else if (i == 3) {
            pRoadRunner->addEvent("ev_4", false, "time > 72", false);
        }
        else if (i == 4) {
            pRoadRunner->addEvent("ev_5", false, "time > 96", false);
        }
        else if (i == 5) {
            pRoadRunner->addEvent("ev_6", false, "time > 120", false);
        }
        else if (i == 6) {
            pRoadRunner->addEvent("ev_7", false, "time > 144", false);
        }
        else if (i == 7) {
            pRoadRunner->addEvent("ev_8", false, "time > 168", false);
        }
        else if (i == 8) {
            pRoadRunner->addEvent("ev_9", false, "time > 192", false);
        }
        else if (i == 9) {
            pRoadRunner->addEvent("ev_10", false, "time > 116", false);
        }


       /* std::stringstream sstrEv;
        sstrEv << "ev_" << i + 1;
        std::stringstream sstrTrigger;
        sstrTrigger << "time > " << i * 24;

        pRoadRunner->addEvent(sstrEv.str(), false, sstrTrigger.str(), false);

        std::stringstream sstrSpeciesId;
        sstrSpeciesId << "QGut + " << 0.00085423766457263053;
        pRoadRunner->addEventAssignment(sstrEv.str(), "QGut", sstrSpeciesId.str(), false);*/

       /* if (i == 0) {
            pRoadRunner->addEventAssignment("ev_1", "QGut", "QGut + 0.00085423766457263053", false);
        }*/
       /* else if (i == 1) {
            pRoadRunner->addEventAssignment("ev_2", "QGut", "QGut + 0.00085423766457263053", false);
        }
        else if (i == 2) {
            pRoadRunner->addEventAssignment("ev_3", "QGut", "QGut + 0.00085423766457263053", false);
        }
        else if (i == 3) {
            pRoadRunner->addEventAssignment("ev_4", "QGut", "QGut + 0.00085423766457263053", false);
        }
        else if (i == 4) {
            pRoadRunner->addEventAssignment("ev_5", "QGut", "QGut + 0.00085423766457263053", false);
        }
        else if (i == 5) {
            pRoadRunner->addEventAssignment("ev_6", "QGut", "QGut + 0.00085423766457263053", false);
        }
        else if (i == 6) {
            pRoadRunner->addEventAssignment("ev_7", "QGut", "QGut + 0.00085423766457263053", false);
        }
        else if (i == 7) {
            pRoadRunner->addEventAssignment("ev_8", "QGut", "QGut + 0.00085423766457263053", false);
        }
        else if (i == 8) {
            pRoadRunner->addEventAssignment("ev_9", "QGut", "QGut + 0.00085423766457263053", false);
        }
        else if (i == 9) {
            pRoadRunner->addEventAssignment("ev_10", "QGut", "QGut + 0.00085423766457263053", false);
        }*/
    }
}

void RemoveEvents(RoadRunner* pRoadRunner) {
    rr::ExecutableModel* pModel = pRoadRunner->getModel();

    std::list <std::string> eventIdsBefore;
    pModel->getEventIds(eventIdsBefore);
    std::for_each(eventIdsBefore.begin(), eventIdsBefore.end(), [&](const std::string& s) {
        pRoadRunner->removeEvent(s, false);
    });
}

void ClockStep(const std::string& cstrMsg) {
    g_nextStep = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds> (g_nextStep - g_step);
    std::cout << "[" << cstrMsg << "] " << duration.count() << " (ms)" << std::endl;
    g_step = g_nextStep;
}


