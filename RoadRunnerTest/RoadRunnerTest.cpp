// RoadRunnerTest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "rr/rrRoadRunner.h"

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
    RoadRunner roadRunner(getSBMLString());
    const ls::DoubleMatrix result = *roadRunner.simulate(0, 1, 101);

    //std::cout << *roadRunner.simulate(0, 1, 101) << std::endl;

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
