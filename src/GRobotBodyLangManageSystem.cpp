// -*- C++ -*-
/*!
 * @file  GRobotBodyLangManageSystem.cpp
 * @brief GRobotBodyLangManageSystem
 * @date $Date$
 *
 * $Id$
 */

#include "GRobotBodyLangManageSystem.h"
#include <math.h>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdlib.h>
#include <typeinfo>

using namespace std;

#define pai 3.14159265

// Module specification
// <rtc-template block="module_spec">
static const char* grobotbodylangmanagesystem_spec[] =
  {
    "implementation_id", "GRobotBodyLangManageSystem",
    "type_name",         "GRobotBodyLangManageSystem",
    "description",       "GRobotBodyLangManageSystem",
    "version",           "1.0.0",
    "vendor",            "hiroyasu_tsuji",
    "category",          "Category",
    "activity_type",     "PERIODIC",
    "kind",              "DataFlowComponent",
    "max_instance",      "1",
    "language",          "C++",
    "lang_type",         "compile",
    // Configuration variables
    "conf.default.ActionMode", "Execution",
    "conf.default.BodyLangList", "../../data.csv",

    // Widget
    "conf.__widget__.ActionMode", "radio",
    "conf.__widget__.BodyLangList", "text",
    // Constraints
    "conf.__constraints__.ActionMode", "(Execution,Generation)",

    "conf.__type__.ActionMode", "string",
    "conf.__type__.BodyLangList", "string",

    ""
  };
// </rtc-template>

/*!
 * @brief constructor
 * @param manager Maneger Object
 */
GRobotBodyLangManageSystem::GRobotBodyLangManageSystem(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_waistmovementIn("waistmovement", m_waistmovement),
    m_current_robot_angleIn("current_robot_angle", m_current_robot_angle),
    m_robot_angleOut("robot_angle", m_robot_angle),
    m_actionmanagePort("actionmanage")

    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
GRobotBodyLangManageSystem::~GRobotBodyLangManageSystem()
{
}



RTC::ReturnCode_t GRobotBodyLangManageSystem::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  addInPort("waistmovement", m_waistmovementIn);
  addInPort("current_robot_angle", m_current_robot_angleIn);
  
  // Set OutPort buffer
  addOutPort("robot_angle", m_robot_angleOut);
  
  // Set service provider to Ports
  m_actionmanagePort.registerProvider("ActionManage", "Action::ActionManage", m_ActionManageProvider);
  
  // Set service consumers to Ports
  
  // Set CORBA Service Ports
  addPort(m_actionmanagePort);
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // Bind variables and configuration variable
  bindParameter("ActionMode", m_ActionMode, "Execution");
  bindParameter("BodyLangList", m_BodyLangList, "../../data.csv");
  // </rtc-template>
  m_ActionManageProvider.GRobotBodyLangData = m_BodyLangList.c_str();
  
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t GRobotBodyLangManageSystem::onFinalize()
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t GRobotBodyLangManageSystem::onStartup(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t GRobotBodyLangManageSystem::onShutdown(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/


RTC::ReturnCode_t GRobotBodyLangManageSystem::onActivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t GRobotBodyLangManageSystem::onDeactivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t GRobotBodyLangManageSystem::onExecute(RTC::UniqueId ec_id)
{
  m_robot_angle.data.length(20);
  int a,b,c,e;
  double d[20];
  std::string bodylanguagename;
  
//************  BodyLanguageGeneration (ボディーランゲージ生成)  ************
  if (m_ActionMode == "Generation"){
    while(e != 2){
      std::cout << "GenerationStart" << std::endl;
      std::cout << "ボディーランゲージ設計手法を選択してください" << std::endl;
      std::cout << "1 : OFFLINE Teaching (オフラインティーチング)" << std::endl;
      std::cout << "2 : Direct Teaching (ダイレクトティーチング)" << std::endl;
      std::cout << "3 : 終了" << std::endl;

      std::cout << "  >>  ";
      std::cin >> a;
      std::cout << std::endl;

      //************  OFFLINE Teaching (オフラインティーチング)  ************
      if (a == 1){
	a = 0;
	while(b != 2){
	  std::cout << "各関節角度を入力してください" << std::endl;
	  
	  std::cout << "Body角度" << std::endl;
	  std::cout << ">>";
	  std::cin >> d[0];
	  std::cout << std::endl;

	  std::cout << "Head角度" << std::endl;
	  std::cout << ">>";
	  std::cin >> d[1];
	  std::cout << std::endl;

	  std::cout << "Rarm0角度" << std::endl;
	  std::cout << ">>";
	  std::cin >> d[2];
	  std::cout << std::endl;
      
	  std::cout << "Rarm1角度" << std::endl;
	  std::cout << ">>";
	  std::cin >> d[3];
	  std::cout << std::endl;
	
	  std::cout << "Rarm2角度" << std::endl;
	  std::cout << ">>";
	  std::cin >> d[4];
	  std::cout << std::endl;

	  std::cout << "Larm0角度" << std::endl;
	  std::cout << ">>";
	  std::cin >> d[5];
	  std::cout << std::endl;

	  std::cout << "Larm1角度" << std::endl;
	  std::cout << ">>";
	  std::cin >> d[6];
	  std::cout << std::endl;

	  std::cout << "Larm2角度" << std::endl;
	  std::cout << ">>";
	  std::cin >> d[7];
	  std::cout << std::endl;

	  std::cout << "Rleg0角度" << std::endl;
	  std::cout << ">>";
	  std::cin >> d[8];
	  std::cout << std::endl;

	  std::cout << "Rleg1角度" << std::endl;
	  std::cout << ">>";
	  std::cin >> d[9];
	  std::cout << std::endl;

	  std::cout << "Rleg2角度" << std::endl;
	  std::cout << ">>";
	  std::cin >> d[10];
	  std::cout << std::endl;

	  std::cout << "Rknee角度" << std::endl;
	  std::cout << ">>";
	  std::cin >> d[11];
	  std::cout << std::endl;

	  std::cout << "Rfoot0角度" << std::endl;
	  std::cout << ">>";
	  std::cin >> d[12];
	  std::cout << std::endl;

	  std::cout << "Rfoot1角度" << std::endl;
	  std::cout << ">>";
	  std::cin >> d[13];
	  std::cout << std::endl;

	  std::cout << "Lleg0角度" << std::endl;
	  std::cout << ">>";
	  std::cin >> d[14];
	  std::cout << std::endl;

	  std::cout << "Lleg1角度" << std::endl;
	  std::cout << ">>";
	  std::cin >> d[15];
	  std::cout << std::endl;

	  std::cout << "Lleg2角度" << std::endl;
	  std::cout << ">>";
	  std::cin >> d[16];
	  std::cout << std::endl;

	  std::cout << "Lknee角度" << std::endl;
	  std::cout << ">>";
	  std::cin >> d[17];
	  std::cout << std::endl;

	  std::cout << "Lfoot0角度" << std::endl;
	  std::cout << ">>";
	  std::cin >> d[18];
	  std::cout << std::endl;

	  std::cout << "Lfoot1角度" << std::endl;
	  std::cout << ">>";
	  std::cin >> d[19];
	  std::cout << std::endl;

	  m_robot_angle.data[0] = -1 * d[0]*(pai/180);
	  m_robot_angle.data[1] = d[1]*(pai/180);
	  m_robot_angle.data[2] = -1 * d[2]*(pai/180);
	  m_robot_angle.data[3] = -1 * d[3]*(pai/180);
	  m_robot_angle.data[4] = -1 * d[4]*(pai/180);
	  m_robot_angle.data[5] = d[5]*(pai/180);
	  m_robot_angle.data[6] = d[6]*(pai/180);
	  m_robot_angle.data[7] = d[7]*(pai/180);
	  m_robot_angle.data[8] = -1 * d[8]*(pai/180);
	  m_robot_angle.data[9] = d[10]*(pai/180);
	  m_robot_angle.data[10] = d[9]*(pai/180);
	  m_robot_angle.data[11] = -1 * d[11]*(pai/180);
	  m_robot_angle.data[12] = -1 * d[12]*(pai/180);
	  m_robot_angle.data[13] = -1 * d[13]*(pai/180);
	  m_robot_angle.data[14] = d[14]*(pai/180);
	  m_robot_angle.data[15] = -1 * d[16]*(pai/180);
	  m_robot_angle.data[16] = -1 * d[15]*(pai/180);
	  m_robot_angle.data[17] = d[17]*(pai/180);
	  m_robot_angle.data[18] = d[18]*(pai/180);
	  m_robot_angle.data[19] = d[19]*(pai/180);
	  
	  m_robot_angleOut.write();

	  std::cout << "入力を完了しますか" << std::endl;
	  std::cout << "1 : データ入力のリセット" << std::endl;
	  std::cout << "2 : 終了" << std::endl;

	  std::cout << "  >>  ";
	  std::cin >> b;
	  std::cout << std::endl;
	}
	b = 0;
	while (c != 2){
	  c = 0;
	  std::cout << "ボディーランゲージ名を入力して下さい" << std::endl;
	  std::cout << "  >>  ";
	  std::cin >> bodylanguagename;
	  std::cout << std::endl;

	  std::vector<std::string> data;
	  std::ifstream ifs(m_BodyLangList.c_str());
	  std::string str;

	  while(getline(ifs, str)){
	    std::istringstream stream(str);
	    std::string field;
	    while(getline(stream, field, ',')){
	      data.push_back(field);
	    }
	  }
	  for(std::vector<std::string>::size_type i = 21; i < data.size(); i+=21){
	    if(data[i] == bodylanguagename){
	      std::cout << " 重複しているボディーランゲージ名があります " << std::endl;
	      bodylanguagename = "";
	      c = 1;
	    }
	  }
	  if (c != 1){
	    c = 2;
	  }
	}
	c = 0;
	std::ofstream ofs(m_BodyLangList.c_str(), std::ios::app);
	ofs << bodylanguagename << "," << d[0] << "," << d[1] << "," << d[2] << "," << d[3]
	    << "," << d[4] << "," << d[5] << "," << d[6] << "," << d[7]<< "," << d[8]
	    << "," << d[9] << "," << d[10] << "," << d[11] << "," << d[12] << "," << d[13]
	    << "," << d[14] << "," << d[15] << "," << d[16] << "," << d[17] << "," << d[18]
	    << "," << d[19]
	    << "," << std::endl;
	std::cout << " BodyLanguageGenerated " << std::endl;

	std::cout << "ボディーランゲージ設定を終了しますか" << std::endl;
	std::cout << "1 : 新規ボディーランゲージ設定" << std::endl;
	std::cout << "2 : 終了" << std::endl;
	
	std::cout << "  >>  ";
	std::cin >> e;
	std::cout << std::endl;
      }

      //************  Direct Teaching (ダイレクトティーチング)  ************
      else if (a == 2){
	a = 0;
	while (b != 2){
	  if (m_current_robot_angleIn.isNew()){
	    m_current_robot_angle.data = m_current_robot_angleIn.read();
	    m_current_robot_angle.data.length();
	    
	    d[0] = -1 * (180/pai) * m_current_robot_angle.data[0];
	    d[1] = (180/pai) * m_current_robot_angle.data[1];
	    d[2] = -1 * (180/pai) * m_current_robot_angle.data[2];
	    d[3] = -1 * (180/pai) * m_current_robot_angle.data[3];
	    d[4] = -1 * (180/pai) * m_current_robot_angle.data[4];
	    d[5] = (180/pai) * m_current_robot_angle.data[5];
	    d[6] = (180/pai) * m_current_robot_angle.data[6];
	    d[7] = (180/pai) * m_current_robot_angle.data[7];
	    d[8] = -1 * (180/pai) * m_current_robot_angle.data[8];
	    d[9] = (180/pai) * m_current_robot_angle.data[10];
	    d[10] = (180/pai) * m_current_robot_angle.data[9];
	    d[11] = -1 * (180/pai) * m_current_robot_angle.data[11];
	    d[12] = -1 * (180/pai) * m_current_robot_angle.data[12];
	    d[13] = -1 * (180/pai) * m_current_robot_angle.data[13];
	    d[14] = (180/pai) * m_current_robot_angle.data[14];
	    d[15] = -1 * (180/pai) * m_current_robot_angle.data[16];
	    d[16] = -1 * (180/pai) * m_current_robot_angle.data[15];
	    d[17] = (180/pai) * m_current_robot_angle.data[17];
	    d[18] = (180/pai) * m_current_robot_angle.data[18];
	    d[19] = (180/pai) * m_current_robot_angle.data[19];
	  }
	  
	  std::cout << "ボディーランゲージ設定を終了しますか" << std::endl;
	  std::cout << "1 : ボディーランゲージ設定のやり直し" << std::endl;
	  std::cout << "2 : 終了" << std::endl;

	  std::cout << "  >>  ";
	  std::cin >> b;
	  std::cout << std::endl;
	}
	b = 0;
	while (c != 2){
	  c = 0;
	  std::cout << "ボディーランゲージ名を入力して下さい" << std::endl;
	  std::cout << "  >>  ";
	  std::cin >> bodylanguagename;
	  std::cout << std::endl;

	  std::vector<std::string> data;
	  std::ifstream ifs(m_BodyLangList.c_str());
	  std::string str;
	  
	  while(getline(ifs, str)){
	    std::istringstream stream(str);
	    std::string field;
	    while(getline(stream, field, ',')){
	      data.push_back(field);
	    }
	  }
	  for(std::vector<std::string>::size_type i = 21; i < data.size(); i+=21){
	    if(data[i] == bodylanguagename){
	      std::cout << " 重複しているボディーランゲージ名があります " << std::endl;
	      bodylanguagename = "";
	      c = 1;
	    }
	  }
	  if (c != 1){
	    c = 2;
	  }
	}
	c = 0;
	std::ofstream ofs(m_BodyLangList.c_str(), std::ios::app);
	ofs << bodylanguagename << "," << d[0] << "," << d[1] << "," << d[2] << "," << d[3]
	    << "," << d[4] << "," << d[5] << "," << d[6] << "," << d[7]<< "," << d[8]
	    << "," << d[9] << "," << d[10] << "," << d[11] << "," << d[12] << "," << d[13]
	    << "," << d[14] << "," << d[15] << "," << d[16] << "," << d[17] << "," << d[18]
	    << "," << d[19]
	    << "," << std::endl;
	std::cout << " BodyLanguageGenerated " << std::endl;

	std::cout << "ボディーランゲージ設定を終了しますか" << std::endl;
	std::cout << "1 : 新規ボディーランゲージ設定" << std::endl;
	std::cout << "2 : 終了" << std::endl;
	
	std::cout << "  >>  ";
	std::cin >> e;
	std::cout << std::endl;

      }

      //************  終了  ************
      else if (a == 3){
	std::cout << "END" << std::endl;
	std::cout << "システムをDeactivateしてください" <<std::endl;
	deactivate(ec_id);
      }
    }
    e = 0;
    std::cout << "END" << std::endl;
    std::cout << "システムをDeactivateしてください" <<std::endl;
    deactivate(ec_id);
  }

//************  BodyLanguageExecution (ボディーランゲージ実行)  ************
  if (m_ActionMode == "Execution" && m_ActionManageProvider.Flag == 1){
    std::cout << "ExecutionStart" << std::endl;

    m_robot_angle.data[0] = m_ActionManageProvider.Body*(pai/180);
    if (m_waistmovementIn.isNew()){
      m_waistmovementIn.read();
      m_robot_angle.data[1] = m_waistmovement.data*(pai/180);
    }
    else {
      m_robot_angle.data[1] = m_ActionManageProvider.Head*(pai/180);
    }
    m_robot_angle.data[2] = -1 * m_ActionManageProvider.Rarm0*(pai/180);
    m_robot_angle.data[3] = -1 * m_ActionManageProvider.Rarm1*(pai/180);
    m_robot_angle.data[4] = -1 * m_ActionManageProvider.Rarm2*(pai/180);
    m_robot_angle.data[5] = m_ActionManageProvider.Larm0*(pai/180);
    m_robot_angle.data[6] = m_ActionManageProvider.Larm1*(pai/180);
    m_robot_angle.data[7] = m_ActionManageProvider.Larm2*(pai/180);
    m_robot_angle.data[8] = -1 * m_ActionManageProvider.Rleg0*(pai/180);
    m_robot_angle.data[9] =  m_ActionManageProvider.Rleg2*(pai/180);
    m_robot_angle.data[10] = m_ActionManageProvider.Rleg1*(pai/180);
    m_robot_angle.data[11] = -1 * m_ActionManageProvider.Rknee*(pai/180);
    m_robot_angle.data[12] = -1 * m_ActionManageProvider.Rfoot0*(pai/180);
    m_robot_angle.data[13] = -1 * m_ActionManageProvider.Rfoot1*(pai/180);
    m_robot_angle.data[14] = m_ActionManageProvider.Lleg0*(pai/180);
    m_robot_angle.data[15] = -1 * m_ActionManageProvider.Lleg2*(pai/180);
    m_robot_angle.data[16] = -1 * m_ActionManageProvider.Lleg1*(pai/180);
    m_robot_angle.data[17] = m_ActionManageProvider.Lknee*(pai/180);
    m_robot_angle.data[18] = m_ActionManageProvider.Lfoot0*(pai/180);
    m_robot_angle.data[19] = m_ActionManageProvider.Lfoot1*(pai/180);
    
    m_robot_angleOut.write();
    m_ActionManageProvider.Flag = 0;
    
  }
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t GRobotBodyLangManageSystem::onAborting(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t GRobotBodyLangManageSystem::onError(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t GRobotBodyLangManageSystem::onReset(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t GRobotBodyLangManageSystem::onStateUpdate(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t GRobotBodyLangManageSystem::onRateChanged(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/



extern "C"
{
 
  void GRobotBodyLangManageSystemInit(RTC::Manager* manager)
  {
    coil::Properties profile(grobotbodylangmanagesystem_spec);
    manager->registerFactory(profile,
                             RTC::Create<GRobotBodyLangManageSystem>,
                             RTC::Delete<GRobotBodyLangManageSystem>);
  }
  
};


