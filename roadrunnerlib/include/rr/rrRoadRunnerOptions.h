/*
* rrRoadRunnerOptions.h
*
*  Created on: Sep 9, 2013
*      Author: andy
*/

#ifndef RRROADRUNNEROPTIONS_H_
#define RRROADRUNNEROPTIONS_H_

#include "rrExporter.h"
#include "Dictionary.h"
#include "Integrator.h"

#include <string>
#include <vector>

namespace rr
{

    /**
    * Options for loading SBML into RoadRunner.
    *
    * Future version may add additional fields to the end of this struct,
    * this way we can maintain binary compatibility with older RoadRunner versions.
    */
    class RR_DECLSPEC LoadSBMLOptions : public BasicDictionary
    {
    public:
        enum LLVM_BACKEND_VALUES {
            // keep unique, counting ModelGeneratorOpt
            MCJIT = (0x1 << 14),
            LLJIT = (0x1 << 15),
            //        LAZYJIT = (0x1 << 0),
        };

        enum LLJIT_OPTIMIZATION_LEVELS {
            NONE = (0x1 << 16),
            LESS = (0x1 << 17),
            DEFAULT = (0x1 << 18),
            AGGRESSIVE = (0x1 << 19)
        };



        // Manually and ineloquently list the backend options for iterating over later.
        static std::vector<LLVM_BACKEND_VALUES> getAllLLVMBackendValues() {
            return std::vector<LLVM_BACKEND_VALUES>({
                MCJIT,
                LLJIT
                });
        };

        // Manually and ineloquently list the lljit optimization options
        static std::vector<LLJIT_OPTIMIZATION_LEVELS> getAllLLJitOptimizationValues() {
            return std::vector<LLJIT_OPTIMIZATION_LEVELS>({
                NONE,
                LESS,
                DEFAULT,
                AGGRESSIVE
                });
        };

        enum ModelGeneratorOpt
        {
            /**
            * perform conservation analysis.
            *
            * This causes a re-ordering of the species, so results generated
            * with this flag enabled can not be compared index wise to results
            * generated otherwise.
            *
            * currently only implemented with the C code generating model
            */
            CONSERVED_MOIETIES = (0x1 << 0),  // => 0x00000001

            /**
            * Should the model be recompiled?
            * The LLVM ModelGenerator maintins a hash table of currently running
            * models. If this flag is NOT set, then the generator will look to see
            * if there is already a running instance of the given model and
            * use the generated code from that one.
            *
            * If only a single instance of a model is run, there is no
            * need to cache the models, and this can safetly be enabled,
            * realizing some performance gains.
            */
            RECOMPILE = (0x1 << 1),  // => 0x00000010

            /**
            * If this is set, then a read-only model is generated. A read-only
            * model can be simulated, but no code is generated to set model
            * values, i.e. parameters, amounts, values, etc...
            *
            * It takes a finite amount of time to generate the model value setting
            * functions, and if they are not needed, one may see some performance
            * gains, especially in very large models.
            */
            READ_ONLY = (0x1 << 2),  // => 0x00000100

            /**
            * Generate accessor functions to allow changing of initial
            * conditions.
            */
            MUTABLE_INITIAL_CONDITIONS = (0x1 << 3),   // => 0x00001000

            /**
            * GVN - This pass performs global value numbering and redundant load
            * elimination cotemporaneously.
            */
            OPTIMIZE_GVN = (0x1 << 4),

            /**
            * CFGSimplification - Merge basic blocks, eliminate unreachable blocks,
            * simplify terminator instructions, etc...
            */
            OPTIMIZE_CFG_SIMPLIFICATION = (0x1 << 5),

            /**
            * InstructionCombining - Combine instructions to form fewer, simple
            * instructions. This pass does not modify the CFG, and has a tendency to make
            * instructions dead, so a subsequent DCE pass is useful.
            */
            OPTIMIZE_INSTRUCTION_COMBINING = (0x1 << 6),

            /**
            * DeadInstElimination - This pass quickly removes trivially dead instructions
            * without modifying the CFG of the function.  It is a BasicBlockPass, so it
            * runs efficiently when queued next to other BasicBlockPass's.
            */
            OPTIMIZE_DEAD_INST_ELIMINATION = (0x1 << 7),

            /**
            * DeadCodeElimination - This pass is more powerful than DeadInstElimination,
            * because it is worklist driven that can potentially revisit instructions when
            * their other instructions become dead, to eliminate chains of dead
            * computations.
            */
            OPTIMIZE_DEAD_CODE_ELIMINATION = (0x1 << 8),

            /**
            * InstructionSimplifier - Remove redundant instructions.
            */
            OPTIMIZE_INSTRUCTION_SIMPLIFIER = (0x1 << 9),

            /**
            * all optimizations, use to check if bit mask has
            * any optimizations.
            */
            OPTIMIZE = OPTIMIZE_GVN | OPTIMIZE_CFG_SIMPLIFICATION |
            OPTIMIZE_INSTRUCTION_COMBINING |
            OPTIMIZE_DEAD_INST_ELIMINATION | OPTIMIZE_DEAD_CODE_ELIMINATION |
            OPTIMIZE_INSTRUCTION_SIMPLIFIER,

            /**
            * Use the LLVM MCJIT JIT engine.
            *
            * Defaults to false.
            *
            * The MCJIT is the new LLVM JIT engine, it is not as well tested as the
            * original JIT engine. Does NOT work on LLVM 3.1
            */
            USE_MCJIT = (0x1 << 10),


            LLVM_SYMBOL_CACHE = (0x1 << 11),

            /**
            * Turn on SBML validation
            */
            TURN_ON_VALIDATION = (0x1 << 12),


        };

        enum LoadOpt
        {
            /**
            * Do not create a default selection list when the model is loaded.
            */
            NO_DEFAULT_SELECTIONS = (0x1 << 0),   // => 0x00000001

            /**
            * Do not create a default steady state selection list when the model is loaded.
            */
            NO_DEFAULT_STEADY_STATE_SELECTIONS = (0x1 << 1)   // => 0x00000010
        };

        /**
        * initializes the struct with the default options.
        */
        LoadSBMLOptions();

        /**
        * creates an object from an existing dictionary.
        */
        LoadSBMLOptions(const Dictionary* dict);

        /**
        * the version this struct
        */
        std::uint16_t version;

        /**
        * sizeof this struct
        */
        std::uint16_t size;

        std::uint32_t modelGeneratorOpt;

        std::uint32_t loadFlags;


        /**
        * sets an item in the internal unordered std::map.
        */
        void setItem(const std::string& key, const rr::Setting& value) override;

        /**
        * gets an item from the internal unordered std::map.
        */
        Setting getItem(const std::string& key) const override;

        /**
        * is there a key matching this name.
        *
        * @return true if this key exists, false otherwise.
        */
        bool hasKey(const std::string& key) const override;

        /**
        * remove a value
        */
        size_t deleteItem(const std::string& key) override;

        /**
        * list of keys in this object.
        */
        std::vector<std::string> getKeys() const override;

        bool getConservedMoietyConversion() const {
            return modelGeneratorOpt & CONSERVED_MOIETIES;
        }

        void setConservedMoietyConversion(bool val) {
            modelGeneratorOpt = val ?
                modelGeneratorOpt | CONSERVED_MOIETIES :
                modelGeneratorOpt & ~CONSERVED_MOIETIES;
        }

        void setValidation(bool val) {
            loadFlags = val ? loadFlags | TURN_ON_VALIDATION : loadFlags & ~TURN_ON_VALIDATION;
        }

        void setLLVMBackend(LoadSBMLOptions::LLVM_BACKEND_VALUES val);

        ~LoadSBMLOptions() override;

        void setLLJitOptimizationLevel(LLJIT_OPTIMIZATION_LEVELS levels);

        //        void setLLJitNumThreads(int numThreads);
        //
        //        int getLLJitNumThreads() const;

                /**
                 * Since we need an integer and modelGeneratorOptions
                 * is a bitfield system for toggling individual bits on or off,
                 * we cannot store this value in modelGeneratorOptions.
                 * Therefore we fall back on the global Config system for this
                 * value.
                 * In short, to set the number of threads used by LLJit do:
                 *    Config::setValue(Config::LLJIT_NUM_THREADS, 7);
                 */
                 //        int llJitNumThreads;
    private:

        // load default values;
        void defaultInit();
    };


    /**
  * @brief This class is frozen, no new features
    * RoadRunner simulation options.
    *
    * This is the full set of options that determines how RoadRunner performs
    * a simulation of an sbml model.
    *
    * This is a superset of the values stored in a sbml test suite settings file, the
    * documentation of the fields which correspond to an sbml test suite settings was
    * taken from http://sbml.org
    */
    class RR_DECLSPEC SimulateOptions //: public BasicDictionary
    {
    public:

        /**
        * init with default options.
        */
        SimulateOptions();

        /**
        * reset the model to the initial state.
        */
        bool reset_model;
        /**
        * Simulate should return a raw result matrix without
        * adding any column names.
        */
        bool structured_result;
        /**
        * Make a copy of the simulation result in Python.
        * Large simulations should have this disabled.
        */
        bool copy_result;

        /**
        * The number of steps at which the output is sampled. The samples are evenly spaced.
        * When a simulation system calculates the data points to record, it will typically
        * divide the duration by the number of time steps. Thus, for X steps, the output
        * will have X+1 data rows.
        */
        int steps;

        /**
        * The start time of the simulation time-series data.
        * Often this is 0, but not necessarily.
        */
        double start;

        /**
        * The duration of the simulation run, in the model's units of time.
        */
        double duration;


        /**
        * The ouptut file for simulation results. If non-empty, then the
        * simulation results are batch-written to output_file every
        * Config::K_ROWS_PER_WRITE rows, and an empty
        * result matrix is returned.
        */
        std::string output_file;

        /**
        * The variables (in addition to time) whose values will be saved in the result.
        * These are SBML model id's. Order is significant, as this determines the order
        * of the columns in the result matrix.
        *
        * Important: if a symbol in this list refers to a species in the model,
        * then that symbol will also be listed in either the amount or concentration
        * lists below.
        *
        * NOTE:If a listed variable has two underscores in it ('__'), that variable
        * is actually present only in a submodel of the main model, from the
        * Hierarchical Model Composition package, in the format submodelID__variableID.
        * If the model is flattened, the variable will appear automatically.
        */
        std::vector<std::string> variables;

        /**
        * A list of the variable whose output in the results file is in amount
        * (not concentration) units. This list of variables must be a subset of
        * the names listed in variables.
        */
        std::vector<std::string> amounts;

        /**
        * A list of the variable whose output in the results file is in concentration
        * (not amount) units. This list of variables must be a subset of the names
        * listed in variables.
        */
        std::vector<std::string> concentrations;

        /*
        * A list of the requested output times.  If set, the simulator will only
        * report simulation output at the requested values.
        */
        std::vector<double> times;

        /**
        * get a description of this object, compatable with python __str__
        */
        std::string toString() const;

        /**
        * get a short descriptions of this object, compatable with python __repr__.
        */
        std::string toRepr() const;

        /*    Use this method to load SimulateOptions from an SBML file. Previously this was done by
         *    passing the filepath into the SimulateOptions constructor. However, the refactor has
         *    removed some properties from SimulateOptions and placed them in specific integrators. As
         *    a result, both the SimulateOptions and Integrator classes will have methods that allow
         *    users to read an SBML settings file.
         */
        void loadSBMLSettings(const std::string& filename);

        //virtual void setItem(const std::string& key, const rr::Setting& value);

        virtual void initialize();

        virtual double getNext(size_t step);

        /**
        * Reset all values to defaults.
        */
        virtual void reset();

    private:

        double hstep; //Used if we have a duration and number of steps, but not 'times'.


    };



    /**
    * A set of options that determine how the top level RoadRunner class
    * should behave.
    */
    struct RR_DECLSPEC RoadRunnerOptions
    {
        enum Options
        {
            /**
            * RoadRunner by default dynamically generates accessor properties
            * for all sbml symbol names on the model object when it is retrieved
            * in Python. This feature is very nice for interactive use, but
            * can slow things down. If this feature is not needed, it
            * can be disabled here.
            */
            DISABLE_PYTHON_DYNAMIC_PROPERTIES = (0x1 << 0), // => 0x00000001
        };

        /**
        * a bitmask of the options specified in the Options enumeration.
        */
        std::uint32_t flags;

        /**
        * step size used for numeric Jacobian calculations.
        */
        double jacobianStepSize;
        double diffStepSize;
        double steadyStateThreshold;
        double fluxThreshold;

        /**
        * load default valued from config.
        */
        RoadRunnerOptions();

    };


} /* namespace rr */
#endif /* RRROADRUNNEROPTIONS_H_ */
