// RoadRunnerTest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include "rr/rrRoadRunner.h"
#include "rr/rrExecutableModel.h"

using namespace rr;

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
    std::ifstream sbmlFile("Resources\\EuroMixGenericPbk_V1.sbml");

    std::stringstream ss;
    std::string line;
    while (std::getline(sbmlFile, line)) {
        ss << line;
    }

    auto sbmlEuroMix = ss.str();

    //RoadRunner roadRunner(getSBMLString());
    RoadRunner roadRunner(sbmlEuroMix);

    // add two events
    const int nrEvents = 10;
    for (int i = 0; i < 10; ++i) {
        std::stringstream sstrEv;
        sstrEv << "ev_" << i + 1;
        std::stringstream sstrTrigger;
        sstrTrigger << "time > " << i * 24;

        roadRunner.addEvent(sstrEv.str(), false, sstrTrigger.str(), false);

        std::stringstream sstrSpeciesId;
        sstrSpeciesId << "QGut + " << 0.00085423766457263053;
        roadRunner.addEventAssignment(sstrEv.str(), "QGut", sstrSpeciesId.str(), false);
    }

    roadRunner.regenerateModel(true, true);

    const ls::DoubleMatrix* result = roadRunner.simulate(0, 1, 101);


    const unsigned rows = result->numRows();
    const unsigned cols = result->numCols();
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            std::cout << "Value [" << r << ", " << c << "] = " << (*result)(r, c) << std::endl;
        }
    }

    rr::ExecutableModel* pModel = roadRunner.getModel();
    //pModel->getEventIds
    //rrllvm::LLVMExecutableModel* pLlvmeModel = reinterpret_cast<rrllvm::LLVMExecutableModel*>(pModel);

    std::list < std::string> eventIdsBefore;
    pModel->getEventIds(eventIdsBefore);


    roadRunner.reset(int(SelectionRecord::ALL));

    std::list < std::string> eventIdsAfter;
    pModel->getEventIds(eventIdsAfter);

    roadRunner.clearModel();
    // after this the model crashes, has become a different instance

    //std::list < std::string> eventIdsAfterClearModel;
    //pModel->getEventIds(eventIdsAfterClearModel);


    RoadRunner roadRunner2(getSBMLString());
    const ls::DoubleMatrix* result2 = roadRunner2.simulate(0, 1, 101);
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            std::cout << "Value [" << r << ", " << c << "] = " << (*result2)(r, c) << std::endl;
        }
    }

    //roadRunner.addEvent()
    const bool loaded = roadRunner.isModelLoaded();
    const string name = roadRunner.getModelName();
    //roadRunner.reset();

    return 0;
}


