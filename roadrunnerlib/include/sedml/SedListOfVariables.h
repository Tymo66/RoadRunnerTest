/**
 * @file SedListOfVariables.h
 * @brief Definition of the SedListOfVariables class.
 * @author DEVISER
 *
 * <!--------------------------------------------------------------------------
 * This file is part of libSEDML. Please visit http://sed-ml.org for more
 * information about SED-ML. The latest version of libSEDML can be found on
 * github: https://github.com/fbergmann/libSEDML/
 * 

 * Copyright (c) 2013-2019, Frank T. Bergmann
 * All rights reserved.
 * 

 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 

 * 1. Redistributions of source code must retain the above copyright notice,
 * this
 * list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 *
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by the
 * Free Software Foundation. A copy of the license agreement is provided in the
 * file named "LICENSE.txt" included with this software distribution and also
 * available online as http://sbml.org/software/libsbml/license.html
 * ------------------------------------------------------------------------ -->
 *
 * @class SedListOfVariables
 * @sbmlbrief{sedml} TODO:Definition of the SedListOfVariables class.
 */


#ifndef SedListOfVariables_H__
#define SedListOfVariables_H__


#include <sedml/common/extern.h>
#include <sedml/common/sedmlfwd.h>


#ifdef __cplusplus


#include <string>


#include <sedml/SedListOf.h>
#include <sedml/SedVariable.h>
#include <sbml/common/libsbml-namespace.h>


LIBSEDML_CPP_NAMESPACE_BEGIN


class LIBSEDML_EXTERN SedListOfVariables : public SedListOf
{

public:

  /**
   * Creates a new SedListOfVariables using the given SED-ML Level and @ p
   * version values.
   *
   * @param level an unsigned int, the SED-ML Level to assign to this
   * SedListOfVariables.
   *
   * @param version an unsigned int, the SED-ML Version to assign to this
   * SedListOfVariables.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedListOfVariables(unsigned int level = SEDML_DEFAULT_LEVEL,
                     unsigned int version = SEDML_DEFAULT_VERSION);


  /**
   * Creates a new SedListOfVariables using the given SedNamespaces object @p
   * sedmlns.
   *
   * @param sedmlns the SedNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedListOfVariables(SedNamespaces *sedmlns);


  /**
   * Copy constructor for SedListOfVariables.
   *
   * @param orig the SedListOfVariables instance to copy.
   */
  SedListOfVariables(const SedListOfVariables& orig);


  /**
   * Assignment operator for SedListOfVariables.
   *
   * @param rhs the SedListOfVariables object whose values are to be used as
   * the basis of the assignment.
   */
  SedListOfVariables& operator=(const SedListOfVariables& rhs);


  /**
   * Creates and returns a deep copy of this SedListOfVariables object.
   *
   * @return a (deep) copy of this SedListOfVariables object.
   */
  virtual SedListOfVariables* clone() const;


  /**
   * Destructor for SedListOfVariables.
   */
  virtual ~SedListOfVariables();


  /**
   * Get a SedVariable from the SedListOfVariables.
   *
   * @param n an unsigned int representing the index of the SedVariable to
   * retrieve.
   *
   * @return the nth SedVariable in this SedListOfVariables or @c NULL if no
   * such object exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addVariable(const SedVariable* object)
   * @see createVariable()
   * @see get(const std::string& sid)
   * @see getNumVariables()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  virtual SedVariable* get(unsigned int n);


  /**
   * Get a SedVariable from the SedListOfVariables.
   *
   * @param n an unsigned int representing the index of the SedVariable to
   * retrieve.
   *
   * @return the nth SedVariable in this SedListOfVariables or @c NULL if no
   * such object exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addVariable(const SedVariable* object)
   * @see createVariable()
   * @see get(const std::string& sid)
   * @see getNumVariables()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  virtual const SedVariable* get(unsigned int n) const;


  /**
   * Get a SedVariable from the SedListOfVariables based on its identifier.
   *
   * @param sid a string representing the identifier of the SedVariable to
   * retrieve.
   *
   * @return the SedVariable in this SedListOfVariables with the given @p sid
   * or @c NULL if no such SedVariable exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addVariable(const SedVariable* object)
   * @see createVariable()
   * @see get(unsigned int n)
   * @see getNumVariables()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  virtual SedVariable* get(const std::string& sid);


  /**
   * Get a SedVariable from the SedListOfVariables based on its identifier.
   *
   * @param sid a string representing the identifier of the SedVariable to
   * retrieve.
   *
   * @return the SedVariable in this SedListOfVariables with the given @p sid
   * or @c NULL if no such SedVariable exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addVariable(const SedVariable* object)
   * @see createVariable()
   * @see get(unsigned int n)
   * @see getNumVariables()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  virtual const SedVariable* get(const std::string& sid) const;


  /**
   * Removes the nth SedVariable from this SedListOfVariables and returns a
   * pointer to it.
   *
   * @param n an unsigned int representing the index of the SedVariable to
   * remove.
   *
   * @return a pointer to the nth SedVariable in this SedListOfVariables.
   *
   * @copydetails doc_warning_returns_owned_pointer
   *
   * @see addVariable(const SedVariable* object)
   * @see createVariable()
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumVariables()
   * @see remove(const std::string& sid)
   */
  virtual SedVariable* remove(unsigned int n);


  /**
   * Removes the SedVariable from this SedListOfVariables based on its
   * identifier and returns a pointer to it.
   *
   * @param sid a string representing the identifier of the SedVariable to
   * remove.
   *
   * @return the SedVariable in this SedListOfVariables based on the identifier
   * or NULL if no such SedVariable exists.
   *
   * @copydetails doc_warning_returns_owned_pointer
   *
   * @see addVariable(const SedVariable* object)
   * @see createVariable()
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumVariables()
   * @see remove(unsigned int n)
   */
  virtual SedVariable* remove(const std::string& sid);


  /**
   * Adds a copy of the given SedVariable to this SedListOfVariables.
   *
   * @param sv the SedVariable object to add.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_LEVEL_MISMATCH, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_VERSION_MISMATCH, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_PKG_VERSION_MISMATCH, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_DUPLICATE_OBJECT_ID, OperationReturnValues_t}
   *
   * @copydetails doc_note_object_is_copied
   *
   * @see createVariable()
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumVariables()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  int addVariable(const SedVariable* sv);


  /**
   * Get the number of SedVariable objects in this SedListOfVariables.
   *
   * @return the number of SedVariable objects in this SedListOfVariables.
   *
   * @see addVariable(const SedVariable* object)
   * @see createVariable()
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  unsigned int getNumVariables() const;


  /**
   * Creates a new SedVariable object, adds it to this SedListOfVariables
   * object and returns the SedVariable object created.
   *
   * @return a new SedVariable object instance.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addVariable(const SedVariable* object)
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumVariables()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  SedVariable* createVariable();


  /**
   * Get a SedVariable from the SedListOfVariables based on the TaskReference
   * to which it refers.
   *
   * @param sid a string representing the "taskReference" attribute of the
   * SedVariable object to retrieve.
   *
   * @return the first SedVariable in this SedListOfVariables based on the
   * given taskReference attribute or NULL if no such SedVariable exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  const SedVariable* getByTaskReference(const std::string& sid) const;


  /**
   * Get a SedVariable from the SedListOfVariables based on the TaskReference
   * to which it refers.
   *
   * @param sid a string representing the "taskReference" attribute of the
   * SedVariable object to retrieve.
   *
   * @return the first SedVariable in this SedListOfVariables based on the
   * given taskReference attribute or NULL if no such SedVariable exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  SedVariable* getByTaskReference(const std::string& sid);


  /**
   * Get a SedVariable from the SedListOfVariables based on the ModelReference
   * to which it refers.
   *
   * @param sid a string representing the "modelReference" attribute of the
   * SedVariable object to retrieve.
   *
   * @return the first SedVariable in this SedListOfVariables based on the
   * given modelReference attribute or NULL if no such SedVariable exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  const SedVariable* getByModelReference(const std::string& sid) const;


  /**
   * Get a SedVariable from the SedListOfVariables based on the ModelReference
   * to which it refers.
   *
   * @param sid a string representing the "modelReference" attribute of the
   * SedVariable object to retrieve.
   *
   * @return the first SedVariable in this SedListOfVariables based on the
   * given modelReference attribute or NULL if no such SedVariable exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  SedVariable* getByModelReference(const std::string& sid);


  /**
   * Returns the XML element name of this SedListOfVariables object.
   *
   * For SedListOfVariables, the XML element name is always
   * @c "listOfVariables".
   *
   * @return the name of this element, i.e. @c "listOfVariables".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSEDML type code for this SedListOfVariables object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SED-ML type code for this object:
   * @sedmlconstant{SEDML_LIST_OF, SedTypeCode_t}.
   *
   * @copydetails doc_warning_typecodes_not_unique
   */
  virtual int getTypeCode() const;


  /**
   * Returns the libSEDML type code for the SED-ML objects contained in this
   * SedListOfVariables object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SED-ML typecode for the objects contained in this
   * SedListOfVariables:
   * @sedmlconstant{SEDML_VARIABLE, SedTypeCode_t}.
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getElementName()
   */
  virtual int getItemTypeCode() const;




  #ifndef SWIG




  #endif /* !SWIG */


protected:


  /** @cond doxygenLibSEDMLInternal */

  /**
   * Creates a new SedVariable in this SedListOfVariables
   */
  virtual SedBase* createObject(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLInputStream&
    stream);

  /** @endcond */


  /** @cond doxygenLibSEDMLInternal */

  /**
   * checks concrete types
   */
  virtual bool isValidTypeForList(SedBase* item);

  /** @endcond */


};



LIBSEDML_CPP_NAMESPACE_END




#endif /* __cplusplus */




#ifndef SWIG




LIBSEDML_CPP_NAMESPACE_BEGIN




BEGIN_C_DECLS


/**
 * Get a SedVariable_t from the SedListOf_t.
 *
 * @param slo the SedListOf_t structure to search.
 *
 * @param n an unsigned int representing the index of the SedVariable_t to
 * retrieve.
 *
 * @return the nth SedVariable_t in this SedListOf_t or @c NULL if no such
 * object exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedListOfVariables_t
 */
LIBSEDML_EXTERN
SedVariable_t*
SedListOfVariables_getVariable(SedListOf_t* slo, unsigned int n);


/**
 * Get a SedVariable_t from the SedListOf_t based on its identifier.
 *
 * @param slo the SedListOf_t structure to search.
 *
 * @param sid a string representing the identifier of the SedVariable_t to
 * retrieve.
 *
 * @return the SedVariable_t in this SedListOf_t with the given @p sid or
 * @c NULL if no such SedVariable_t exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedListOfVariables_t
 */
LIBSEDML_EXTERN
SedVariable_t*
SedListOfVariables_getById(SedListOf_t* slo, const char *sid);


/**
 * Removes the nth SedVariable_t from this SedListOf_t and returns a pointer to
 * it.
 *
 * @param slo the SedListOf_t structure to search.
 *
 * @param n an unsigned int representing the index of the SedVariable_t to
 * remove.
 *
 * @return a pointer to the nth SedVariable_t in this SedListOf_t.
 *
 * @copydetails doc_warning_returns_owned_pointer
 *
 * @memberof SedListOfVariables_t
 */
LIBSEDML_EXTERN
SedVariable_t*
SedListOfVariables_remove(SedListOf_t* slo, unsigned int n);


/**
 * Removes the SedVariable_t from this SedListOf_t based on its identifier and
 * returns a pointer to it.
 *
 * @param slo the SedListOf_t structure to search.
 *
 * @param sid a string representing the identifier of the SedVariable_t to
 * remove.
 *
 * @return the SedVariable_t in this SedListOf_t based on the identifier or
 * NULL if no such SedVariable_t exists.
 *
 * @copydetails doc_warning_returns_owned_pointer
 *
 * @memberof SedListOfVariables_t
 */
LIBSEDML_EXTERN
SedVariable_t*
SedListOfVariables_removeById(SedListOf_t* slo, const char* sid);




END_C_DECLS




LIBSEDML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !SedListOfVariables_H__ */


