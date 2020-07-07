/*
 * Copyright 2019-present Open Networking Foundation
 * Copyright (c) 2003-2018, Great Software Laboratory Pvt. Ltd.
 * Copyright (c) 2017 Intel Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

extern "C"
{
#include "json_data.h"
}

#include "mme_app.h"
#include "err_codes.h"

static int get_mcc_mnc(char *plmn, uint16_t *mcc_i, uint16_t *mnc_i, uint16_t *mnc_digits);

/**
 * @brief Initialize json parser
 * @param None
 * @return void
 */
void
init_parser(char *path)
{
	load_json(path);
}

/* int_alg: "EIA1, EIA2, EIA0" */
static int
getIntAlgOrder(char *alg_list, uint8_t* alg_order)
{
    char *subString;
    log_msg(LOG_DEBUG, "alg_list : %s\n", alg_list); 
    subString = strtok(alg_list,"[]");
    log_msg(LOG_DEBUG, "substring : %s\n", subString); 
    //subString = strtok(NULL,"]");
    //log_msg(LOG_DEBUG, "substring : %s\n", subString); 

    char token[] = ",";
    char *saved_comma=NULL;
    char *alg[3] = {NULL,NULL,NULL};
    alg[0] = strtok_r(subString, token, &saved_comma);
    alg[1] = strtok_r(NULL, token, &saved_comma);
    alg[2] = strtok_r(NULL, token, &saved_comma);

    for(int i = 0;i < 3; i++)
    {
        log_msg(LOG_DEBUG, "algs : %s\n", alg[i]);
        if(alg[i] != NULL)
        {
            if(!strcmp(alg[i],"EIA0"))
            {
                alg_order[i] = 0;
            }
            else if(!strcmp(alg[i],"EIA1"))
            {
                alg_order[i] = 1;
            }
            else if(!strcmp(alg[i],"EIA2"))
            {
                alg_order[i] = 2;
            }
            else
            {
                alg_order[i] = 0;
            }
        }
        else
        {
            alg_order[i] = 0;
        }
    }
    
    return 0;
}


/* sec_alg: "EEA0, EEA1, EEA2" */
static int
getSecAlgOrder(char *alg_list, uint8_t* alg_order)
{
    char *subString;
    log_msg(LOG_DEBUG, "alg_list : %s\n", alg_list); 
    subString = strtok(alg_list,"[]");
    log_msg(LOG_DEBUG, "substring : %s\n", subString); 

    char token[] = ",";
    char *saved_comma=NULL;
    char *alg[3] = {NULL,NULL,NULL};
    char *temp_token = subString;
    char *temp;
    //while ((temp = strtok_r(temp_token, ",", &temp_token)))
    //    log_msg(LOG_DEBUG, "token : %s\n", temp); 
    
    alg[0] = strtok_r(subString, token, &saved_comma);
    alg[1] = strtok_r(NULL, token, &saved_comma);
    alg[2] = strtok_r(NULL, token, &saved_comma);

    for(int i = 0;i < 3; i++)
    {
        log_msg(LOG_DEBUG, "algs : %s\n", alg[i]);
        if(alg[i] != NULL)
        {
            if(!strcmp(alg[i],"EEA0"))
            {
                alg_order[i] = 0;
            }
            else if(!strcmp(alg[i],"EEA1"))
            {
                alg_order[i] = 1;
            }
            else if(!strcmp(alg[i],"EEA2"))
            {
                alg_order[i] = 2;
            }
            else
            {
                alg_order[i] = 0;
            }
        }
        else
        {
            alg_order[i] = 0;
        }
    }
    
    return 0;
}
/**
 * @brief parser mme-app input json file
 * @param None
 * @return int as SUCCESS or FAIL
 */
int
parse_mme_conf(mme_config *config)
{
	log_msg(LOG_INFO, "Parsing config %s \n", __FUNCTION__);
	/*mme own information*/
	config->mme_name = get_string_scalar((char *)("mme.name"));
	if(NULL == config->mme_name) return E_PARSING_FAILED;

	config->mme_ip_addr = get_ip_scalar((char *)("mme.ip_addr"));
	if(E_PARSING_FAILED == config->mme_ip_addr) return E_PARSING_FAILED;

	config->logging = get_string_scalar((char *)("mme.logging"));
	if(NULL == config->logging) 
    { 
	  log_msg(LOG_INFO, "Missing logging config");
      config->logging = (char *)calloc(1, strlen("debug")+1);
      strncpy(config->logging, "debug", strlen("debug")+1);
    }

	config->mcc_dig1 = get_int_scalar((char *)("mme.mcc.dig1"));
	if(E_PARSING_FAILED == config->mcc_dig1) return E_PARSING_FAILED;
	config->mcc_dig2 = get_int_scalar((char *)("mme.mcc.dig2"));
	if(E_PARSING_FAILED == config->mcc_dig1) return E_PARSING_FAILED;
	config->mcc_dig3 = get_int_scalar((char *)("mme.mcc.dig3"));
	if(E_PARSING_FAILED == config->mcc_dig1) return E_PARSING_FAILED;
	config->mcc_dig1 = get_int_scalar((char *)("mme.mnc.dig1"));
	if(E_PARSING_FAILED == config->mcc_dig1) return E_PARSING_FAILED;
	config->mnc_dig2 = get_int_scalar((char *)("mme.mnc.dig2"));
	if(E_PARSING_FAILED == config->mcc_dig1) return E_PARSING_FAILED;
	config->mnc_dig3 = get_int_scalar((char *)("mme.mnc.dig3"));
	if(E_PARSING_FAILED == config->mcc_dig1) return E_PARSING_FAILED;

	config->mme_group_id = get_int_scalar((char *)("mme.group_id"));
	if(-1 == config->mme_group_id) return -1;

	config->mme_code = get_int_scalar((char *)("mme.code"));
	if(-1 == config->mme_code) return -1;

	char* int_alg_list = get_string_scalar((char *)("mme.security.int_alg_list"));
	if(E_PARSING_FAILED == config->mcc_dig1) return E_PARSING_FAILED;
	char* sec_alg_list = get_string_scalar((char *)("mme.security.sec_alg_list"));
	if(E_PARSING_FAILED == config->mcc_dig1) return E_PARSING_FAILED;
    getIntAlgOrder(int_alg_list, config->integrity_alg_order);
    getSecAlgOrder(sec_alg_list, config->ciphering_alg_order);
	uint16_t count=1;
	while(1) {
		char name[100] = {'\0'};
		sprintf(name,"%s%d","mme.plmnlist.plmn",count);
		char *plmn = get_string_scalar(name);
		if(NULL == plmn) {
			// over
			break;
		}
		log_msg(LOG_INFO, "Parsed plmn %s \n", plmn);
		uint16_t mcc_i, mnc_i, mnc_digits=3;
		get_mcc_mnc(plmn, &mcc_i, &mnc_i, &mnc_digits);
		config->plmn_mcc_mnc[count-1].mcc = mcc_i;
		config->plmn_mcc_mnc[count-1].mnc = mnc_i;
		log_msg(LOG_INFO, "Parsed plmn mcc - %d mnc - %d \n", mcc_i, mnc_i);
		unsigned char mcc_dig_1 = mcc_i / 100; 
		unsigned char mcc_dig_2 = (mcc_i / 10) % 10; 
		unsigned char mcc_dig_3 = mcc_i % 10; 
		unsigned char mnc_dig_1; 
		unsigned char mnc_dig_2;
		unsigned char mnc_dig_3;
		if(mnc_digits == 2) // 01
		{
			mnc_dig_1 = 0x0F;
			mnc_dig_2 = mnc_i / 10;
		}
		else
		{
			mnc_dig_1 = mnc_i / 100;
			mnc_dig_2 = (mnc_i / 10) % 10; 
		}
		mnc_dig_3 = mnc_i % 10;
		config->plmns[count-1].idx[0] = (mcc_dig_2 << 4) | (mcc_dig_1);
		config->plmns[count-1].idx[1] = (mnc_dig_1 << 4) | (mcc_dig_3);
		config->plmns[count-1].idx[2] = (mnc_dig_3 << 4) | (mnc_dig_2);
        config->plmns[count-1].mnc_digits = mnc_digits;
		log_msg(LOG_INFO, "Configured plmn %x %x %x", config->plmns[count-1].idx[0], config->plmns[count-1].idx[1], config->plmns[count-1].idx[2]); 
		count++;
	}
	config->num_plmns = count - 1;

	return SUCCESS;
}

static int
get_mcc_mnc(char *plmn, uint16_t *mcc_i, uint16_t *mnc_i, uint16_t *mnc_digits)
{
	char *token = (char*)(",");
	char *saved_comma=NULL;
	char *mcc = strtok_r(plmn, token, &saved_comma);
	char *mnc = strtok_r(NULL, token, &saved_comma);

	char *saved_e=NULL;
	char *token_e = (char*)("=");
	char *mcc_f = strtok_r(mcc, token_e, &saved_e);
	mcc_f = strtok_r(NULL, token_e, &saved_e);
	*mcc_i = atoi(mcc_f);

	saved_e=NULL;
	char *mnc_f = strtok_r(mnc, token_e, &saved_e);
	mnc_f = strtok_r(NULL, token_e, &saved_e);
    *mnc_digits = strlen(mnc_f);
	*mnc_i = atoi(mnc_f);
	return 0;
}
