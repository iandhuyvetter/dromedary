//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "DromedaryTestApp.h"
#include "DromedaryApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

template <>
InputParameters
validParams<DromedaryTestApp>()
{
  InputParameters params = validParams<DromedaryApp>();
  return params;
}

DromedaryTestApp::DromedaryTestApp(InputParameters parameters) : MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  DromedaryApp::registerObjectDepends(_factory);
  DromedaryApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  DromedaryApp::associateSyntaxDepends(_syntax, _action_factory);
  DromedaryApp::associateSyntax(_syntax, _action_factory);

  Moose::registerExecFlags(_factory);
  ModulesApp::registerExecFlags(_factory);
  DromedaryApp::registerExecFlags(_factory);

  bool use_test_objs = getParam<bool>("allow_test_objects");
  if (use_test_objs)
  {
    DromedaryTestApp::registerObjects(_factory);
    DromedaryTestApp::associateSyntax(_syntax, _action_factory);
    DromedaryTestApp::registerExecFlags(_factory);
  }
}

DromedaryTestApp::~DromedaryTestApp() {}

void
DromedaryTestApp::registerApps()
{
  registerApp(DromedaryApp);
  registerApp(DromedaryTestApp);
}

void
DromedaryTestApp::registerObjects(Factory & /*factory*/)
{
  /* Uncomment Factory parameter and register your new test objects here! */
}

void
DromedaryTestApp::associateSyntax(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
  /* Uncomment Syntax and ActionFactory parameters and register your new test objects here! */
}

void
DromedaryTestApp::registerExecFlags(Factory & /*factory*/)
{
  /* Uncomment Factory parameter and register your new execute flags here! */
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
DromedaryTestApp__registerApps()
{
  DromedaryTestApp::registerApps();
}

// External entry point for dynamic object registration
extern "C" void
DromedaryTestApp__registerObjects(Factory & factory)
{
  DromedaryTestApp::registerObjects(factory);
}

// External entry point for dynamic syntax association
extern "C" void
DromedaryTestApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory)
{
  DromedaryTestApp::associateSyntax(syntax, action_factory);
}

// External entry point for dynamic execute flag loading
extern "C" void
DromedaryTestApp__registerExecFlags(Factory & factory)
{
  DromedaryTestApp::registerExecFlags(factory);
}
