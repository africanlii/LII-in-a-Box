<?php

	function legislationtype_form_alter(&$form, &$form_state, $form_id) {
		if($form_id == 'legislationtype_node_form') { 
			//un-require the title and hide it, we will auto title the content on submit
			$form['title']['#required'] = TRUE;
			$form['#validate'][] = 'legislationtype_node_form_submit';
			//dpm($form['#validate']);
			 
		} 
 	}

 	function legislationtype_node_form_submit(&$form, &$form_state) {
 
		$ct_code = strtoupper(variable_get('site_default_country'));
		$court_name = $form_state['input']['title'];
			
	
	}
