

 /*
 * Copyright 2021-present Infosys Limited
 *
 * SPDX-License-Identifier: Apache-2.0
 */
 
 /******************************************************
 * dedBearerActProcedureStates.h
 * This is an auto generated file.
 * Please do not edit this file.
 * All edits to be made through template source file
 * <TOP-DIR/scripts/SMCodeGen/templates/stateMachineTmpls/state.h.tt>
 ******************************************************/
 #ifndef __DED_BEARER_ACT_PROCEDURE__
 #define __DED_BEARER_ACT_PROCEDURE__

 #include "state.h"

 namespace mme {
	class DedActStart : public SM::State
	{
		public:
			/******************************************
			* Instance 
			*    Creates static instance for the state
			*******************************************/
			static DedActStart* Instance();

			/****************************************
			* DedActStart
			*    Destructor
			****************************************/
			~DedActStart();			
			
			/******************************************
			* initialize
			*  Initializes action handlers for the state
			* and next state
			******************************************/
			void initialize();

			/*****************************************
			* returns stateId
			*****************************************/
			uint16_t getStateId() const;

			/*****************************************
			* returns stateName
			*****************************************/
			const char* getStateName() const;

		protected:
			/****************************************
			* DedActStart
			*    Protected constructor
			****************************************/
			DedActStart();  
	};
	
	class DedActWfBearerAndSessionSetup : public SM::State
	{
		public:
			/******************************************
			* Instance 
			*    Creates static instance for the state
			*******************************************/
			static DedActWfBearerAndSessionSetup* Instance();

			/****************************************
			* DedActWfBearerAndSessionSetup
			*    Destructor
			****************************************/
			~DedActWfBearerAndSessionSetup();			
			
			/******************************************
			* initialize
			*  Initializes action handlers for the state
			* and next state
			******************************************/
			void initialize();

			/*****************************************
			* returns stateId
			*****************************************/
			uint16_t getStateId() const;

			/*****************************************
			* returns stateName
			*****************************************/
			const char* getStateName() const;

		protected:
			/****************************************
			* DedActWfBearerAndSessionSetup
			*    Protected constructor
			****************************************/
			DedActWfBearerAndSessionSetup();  
	};
	
	class DedActWfSessionSetup : public SM::State
	{
		public:
			/******************************************
			* Instance 
			*    Creates static instance for the state
			*******************************************/
			static DedActWfSessionSetup* Instance();

			/****************************************
			* DedActWfSessionSetup
			*    Destructor
			****************************************/
			~DedActWfSessionSetup();			
			
			/******************************************
			* initialize
			*  Initializes action handlers for the state
			* and next state
			******************************************/
			void initialize();

			/*****************************************
			* returns stateId
			*****************************************/
			uint16_t getStateId() const;

			/*****************************************
			* returns stateName
			*****************************************/
			const char* getStateName() const;

		protected:
			/****************************************
			* DedActWfSessionSetup
			*    Protected constructor
			****************************************/
			DedActWfSessionSetup();  
	};
	
	class DedActWfBearerSetup : public SM::State
	{
		public:
			/******************************************
			* Instance 
			*    Creates static instance for the state
			*******************************************/
			static DedActWfBearerSetup* Instance();

			/****************************************
			* DedActWfBearerSetup
			*    Destructor
			****************************************/
			~DedActWfBearerSetup();			
			
			/******************************************
			* initialize
			*  Initializes action handlers for the state
			* and next state
			******************************************/
			void initialize();

			/*****************************************
			* returns stateId
			*****************************************/
			uint16_t getStateId() const;

			/*****************************************
			* returns stateName
			*****************************************/
			const char* getStateName() const;

		protected:
			/****************************************
			* DedActWfBearerSetup
			*    Protected constructor
			****************************************/
			DedActWfBearerSetup();  
	};
	
};
#endif // __DED_BEARER_ACT_PROCEDURE__