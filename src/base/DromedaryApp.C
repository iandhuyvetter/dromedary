#include "DromedaryApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

template <>
InputParameters
validParams<DromedaryApp>()
{
  InputParameters params = validParams<MooseApp>();
  return params;
}

DromedaryApp::DromedaryApp(InputParameters parameters) : MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  DromedaryApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  DromedaryApp::associateSyntax(_syntax, _action_factory);

  Moose::registerExecFlags(_factory);
  ModulesApp::registerExecFlags(_factory);
  DromedaryApp::registerExecFlags(_factory);
}

DromedaryApp::~DromedaryApp() {}

void
DromedaryApp::registerApps()
{
  registerApp(DromedaryApp);
}

void
DromedaryApp::registerObjects(Factory & factory)
{
    Registry::registerObjectsTo(factory, {"DromedaryApp"});
}

void
DromedaryApp::associateSyntax(Syntax & /*syntax*/, ActionFactory & action_factory)
{
  Registry::registerActionsTo(action_factory, {"DromedaryApp"});

  /* Uncomment Syntax parameter and register your new production objects here! */
}

void
DromedaryApp::registerObjectDepends(Factory & /*factory*/)
{
}

void
DromedaryApp::associateSyntaxDepends(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
}

void
DromedaryApp::registerExecFlags(Factory & /*factory*/)
{
  /* Uncomment Factory parameter and register your new execution flags here! */
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
DromedaryApp__registerApps()
{
  DromedaryApp::registerApps();
}

extern "C" void
DromedaryApp__registerObjects(Factory & factory)
{
  DromedaryApp::registerObjects(factory);
}

extern "C" void
DromedaryApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory)
{
  DromedaryApp::associateSyntax(syntax, action_factory);
}

extern "C" void
DromedaryApp__registerExecFlags(Factory & factory)
{
  DromedaryApp::registerExecFlags(factory);
}
