/*=========================================================================

  Program:   Insight Segmentation & Registration Toolkit
  Module:    $RCSfile$
  Language:  C++
  Date:      $Date$
  Version:   $Revision$


  Copyright (c) 2000 National Library of Medicine
  All rights reserved.

  See COPYRIGHT.txt for copyright details.

=========================================================================*/
#include "cmWin32DefinesRule.h"

cmWin32DefinesRule::cmWin32DefinesRule()
{
#ifndef _WIN32
  this->EnabledOff();
#endif
}

// cmWin32DefinesRule
bool cmWin32DefinesRule::Invoke(std::vector<std::string>& args)
{
  if(args.size() < 1 )
    {
    this->SetError("called with incorrect number of arguments");
    return false;
    }
  for(std::vector<std::string>::iterator i = args.begin();
      i != args.end(); ++i)
    {
    m_Makefile->AddDefineFlag((*i).c_str());
    }
  return true;
}

