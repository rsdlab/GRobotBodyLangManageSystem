﻿// -*-C++-*-
/*!
 * @file  ActionManageSVC_impl.cpp
 * @brief Service implementation code of ActionManage.idl
 *
 */

#include "ActionManageSVC_impl.h"

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdlib.h>

using namespace std;

/*
 * Example implementational code for IDL interface Action::ActionManage
 */
Action_ActionManageSVC_impl::Action_ActionManageSVC_impl()
{
  // Please add extra constructor code here.
}


Action_ActionManageSVC_impl::~Action_ActionManageSVC_impl()
{
  // Please add extra destructor code here.
}


/*
 * Methods corresponding to IDL attributes and operations
 */
void Action_ActionManageSVC_impl::read(const char* actionid)
{
  // Please insert your code here and remove the following warning pragma
#ifndef WIN32
  #warning "Code missing in function <void Action_ActionManageSVC_impl::read(const char* actionid)>"
  vector<string> data;
  std::ifstream ifs(GRobotBodyLangData.c_str());
  std::string str;
  
  while(getline(ifs, str)){
    istringstream stream(str);
    string field;
    while(getline(stream, field, ',')){
      data.push_back(field);
    }
  }
  for(vector<string>::size_type i = 21; i < data.size(); i+=21){
    if(data[i] == actionid){
      Body = atof(data [i+1].c_str());
      Head = atof(data [i+2].c_str());
      Rarm0 = atof(data [i+3].c_str());
      Rarm1 = atof(data [i+4].c_str());
      Rarm2 = atof(data [i+5].c_str());
      Larm0 = atof(data [i+6].c_str());
      Larm1 = atof(data [i+7].c_str());
      Larm2 = atof(data [i+8].c_str());
      Rleg0 = atof(data [i+9].c_str());
      Rleg1 = atof(data [i+10].c_str());
      Rleg2 = atof(data [i+11].c_str());
      Rknee = atof(data [i+12].c_str());
      Rfoot0 = atof(data [i+13].c_str());
      Rfoot1 = atof(data [i+14].c_str());
      Lleg0 = atof(data [i+15].c_str());
      Lleg1 = atof(data [i+16].c_str());
      Lleg2 = atof(data [i+17].c_str());
      Lknee = atof(data [i+18].c_str());
      Lfoot0 = atof(data [i+19].c_str());
      Lfoot1 = atof(data [i+20].c_str());
      Flag = 1;

      std::cout << "BodyLanguageName : " << actionid << std::endl;
      std::cout << "Body : " << Body << std::endl;
      std::cout << "Head : " << Head << std::endl;
      std::cout << "Rarm0 : " << Rarm0 << std::endl;
      std::cout << "Rarm1 : " << Rarm1 << std::endl;
      std::cout << "Rarm2 : " << Rarm2 << std::endl;
      std::cout << "Larm0 : " << Larm0 << std::endl;
      std::cout << "Larm1 : " << Larm1 << std::endl;
      std::cout << "Larm2 : " << Larm2 << std::endl;
      std::cout << "Rleg0 : " << Rleg0 << std::endl;
      std::cout << "Rleg1 : " << Rleg1 << std::endl;
      std::cout << "Rleg2 : " << Rleg2 << std::endl;
      std::cout << "Rknee : " << Rknee << std::endl;
      std::cout << "Rfoot0 : " << Rfoot0 << std::endl;
      std::cout << "Rfoot1 : " << Rfoot1 << std::endl;
      std::cout << "Lleg0 : " << Lleg0 << std::endl;
      std::cout << "Lleg1 : " << Lleg1 << std::endl;
      std::cout << "Lleg2 : " << Lleg2 << std::endl;
      std::cout << "Lknee : " << Lknee << std::endl;
      std::cout << "Lfoot0 : " << Lfoot0 << std::endl;
      std::cout << "Lfoot1 : " << Lfoot1 << std::endl;
    }
  }
#endif
}



// End of example implementational code



