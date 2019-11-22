// -*-C++-*-
/*!
 * @file  ActionManageSVC_impl.h
 * @brief Service implementation header of ActionManage.idl
 *
 */

#include "ActionManageSkel.h"
#include <iostream>

#ifndef ACTIONMANAGESVC_IMPL_H
#define ACTIONMANAGESVC_IMPL_H
 
/*!
 * @class Action_ActionManageSVC_impl
 * Example class implementing IDL interface Action::ActionManage
 */
class Action_ActionManageSVC_impl
 : public virtual POA_Action::ActionManage,
   public virtual PortableServer::RefCountServantBase
{
 private:
   // Make sure all instances are built on the heap by making the
   // destructor non-public
   //virtual ~Action_ActionManageSVC_impl();

 public:
  /*!
   * @brief standard constructor
   */
   Action_ActionManageSVC_impl();
  /*!
   * @brief destructor
   */
   virtual ~Action_ActionManageSVC_impl();

   // attributes and operations
   void read(const char* actionid);

   std::string GRobotBodyLangData;

   int Flag;

   double Body;
   double Head;
  
   double Rarm0;
   double Rarm1;
   double Rarm2;
  
   double Larm0;
   double Larm1;
   double Larm2;
  
   double Rleg0;
   double Rleg1;
   double Rleg2;
  
   double Rknee;
  
   double Rfoot0;
   double Rfoot1;

   double Lleg0;
   double Lleg1;
   double Lleg2;
  
   double Lknee;
  
   double Lfoot0;
   double Lfoot1;

};



#endif // ACTIONMANAGESVC_IMPL_H


