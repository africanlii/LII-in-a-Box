<?php

	function courtnamesadd_form_alter(&$form, &$form_state, $form_id) {
		if($form_id == 'courtnamesadd_node_form') { 
			//un-require the title and hide it, we will auto title the content on submit
			$form['title']['#required'] = TRUE;
			//$form['title']['#type'] = 'value';
			//$form['#submit'][] = 'courtnamesadd_node_form_submit';
			$form['#validate'][] = 'courtnamesadd_node_form_submit';
			//dpm($form['#validate']);
			 
		} 
 	}

 	function courtnamesadd_node_form_submit(&$form, &$form_state) {
 
		$ct_code = strtoupper(variable_get('site_default_country'));
		$court_name = $form_state['input']['title'];
		//print_r($court_name_ar);exit;
		//echo count($court_name_ar);exit;

		$bundle = 'courtnamesadd';
  		$result = db_query("SELECT field_courtmnc_value FROM {field_data_field_courtmnc} WHERE bundle = :bundle",array(':bundle' => $bundle,)); 

		$mncvals_array = array();

		foreach($result as $names){
			$mncvals_array[] = $names->field_courtmnc_value;
		}
			
		$st_mnc_ar = explode(' ',$court_name);
		$alpha1 = $st_mnc_ar[0][0];
		$alpha2 = $st_mnc_ar[1][0];
		$mncval = $ct_code.strtoupper($alpha1.$alpha2);

		if(in_array($mncval,$mncvals_array)){
			$st_mnc_ar = explode(' ',$court_name);
			$alpha1 = $st_mnc_ar[0][0].$st_mnc_ar[0][1].$st_mnc_ar[0][2];
			//$alpha2 = $st_mnc_ar[1][0];
			$mncval = $ct_code.strtoupper($alpha1);
		}

		if($form_state['input']['field_courtmnc']['und'][0]['value'] == ''){
			$form_state['values']['field_courtmnc']['und'][0]['value'] = $mncval;

		}

		if(in_array($form_state['input']['field_courtmnc']['und'][0]['value'],$mncvals_array)){
			form_set_error('title', t('MNC code added already exists.'));
		}		
	
	}
