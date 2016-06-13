<?php

	/**
	 * Options callback for simple_content_type_checkboxes field
	 * @return - returns an indexed array as integer => string
	 */
	//function to create dropdown values of court names
	function _judgment_options_list(){

		$bundle = 'courtnamesadd';
  		$mnc_code = 'scza';
  		/*$result = db_query("SELECT entity_id,revision_id,field_courtname_value FROM {field_revision_field_courtname} WHERE bundle = :bundle",array(':bundle' => $bundle,)); 
  		foreach($result as $option){
			$options[$option->field_courtname_value] = $option->field_courtname_value;
		}*/
		
		$result = db_query("SELECT title FROM {node} WHERE type = :bundle",array(':bundle' => $bundle,));
		$options = array();

		foreach($result as $option){
			$options[$option->title] = $option->title;
		}
			
		return $options;
	}

	function judgment_form_alter(&$form, &$form_state, $form_id) {
		if($form_id == 'judgment_node_form') {
		 
			//un-require the title and hide it, we will auto title the content on submit
			$form['title']['#required'] = FALSE;
			$form['title']['#type'] = 'value';
			$form['#submit'][] = 'judgment_node_form_submit';
		 
		} 
	 
	}

	/**
	* Custom submit handler for observation nodes to alter the title
	*/
	function judgment_node_form_submit(&$form, &$form_state) {
	 
		//if you want any of the current users info in the title routine...
		$current_user = user_load($form_state['values']['uid']);
		//$title = $current_user->name;

		//$jdate = date('j F Y', $form_state['input']['field_jdate']['und'][0]['value']);
		//$jdate = date('j F Y',strtotime($form_state['input']['field_jdate']['und'][0]['value']));
		$jdate = $form_state['input']['field_jdate']['und'][0]['value']['date'];

		$query = db_query("SELECT MAX(field_jno_value) as max_jno FROM field_revision_field_jno")->fetchCol();
		
		//echo $query[0];exit;
		$max_jno = $query[0];



		if($form_state['input']['field_jno']['und'][0]['value'] == ''){
		
			$form_state['values']['field_jno']['und'][0]['value'] = $max_jno+1;
			//echo $form_state['input']['field_jno']['und'][0]['value'] = $max_jno+1;exit;
		}

		$country_code = strtoupper(variable_get('site_default_country'));
		//echo strtoupper($country_code);exit;

		//Automating MNC code
		/*$court_name_ar = explode(' ',$form_state['input']['field_issuingcourt_select']['und']);
		$alpha1 = $court_name_ar[0][0];
		$alpha2 = $court_name_ar[1][0];*/
		$mnc_year = date('Y',strtotime($form_state['input']['field_jdate']['und'][0]['value']['date']));
		$mnc_jno = $form_state['values']['field_jno']['und'][0]['value'];

		
		//$mncval = "[".$mnc_year."] ".$country_code.strtoupper($alpha1.$alpha2)." ".$mnc_jno;

		echo '<pre>';
		//print_r($form_state['input']);exit;

		$court_name = $form_state['input']['field_issuingcourt_select']['und'];
		$bundle = 'courtnamesadd';
  		$result = db_query("SELECT mnc.field_courtmnc_value FROM {field_data_field_courtmnc} mnc 
  			INNER JOIN {node} nd
  			ON nd.nid = mnc.entity_id
  			AND nd.title = '$court_name'
  			AND nd.type = '$bundle' "); 
  		$record = $result->fetchObject();

  		$mncval = "[".$mnc_year."] ".$record->field_courtmnc_value." ".$mnc_jno;
  		//echo $record->field_courtmnc_value;exit;

		if($form_state['input']['field_mnc']['und'][0]['value'] == ''){
			$form_state['values']['field_mnc']['und'][0]['value'] = $mncval;
		}


		//echo '<pre>';
		//print_r($form_state['values']);exit;
		

		//print($form_state['input']['field_issuingcourt_select']['und']);exit;
		//$court = $form_state['input']['field_issuingcourt_select']['und'];
		//echo '<pre>';
		//print_r($form_state['field']['field_download']['und']['instance']['settings']['file_directory']);exit;
		//$form_state['field']['field_download']['und']['instance']['settings']['file_directory'] = $form_state['field']['field_download']['und']['instance']['settings']['file_directory'].'/'.$court;


		//echo $jdate;exit;
		//$title = $form_state['input']['field_casename']['und'][0]['value'] .' ('.$form_state['input']['field_casenumber']['und'][0]['value'].')' .$form_state['input']['field_mnc']['und'][0]['value'] .' ('.$jdate.')';

		$title = $form_state['input']['field_casename']['und'][0]['value'] .' ('.$form_state['input']['field_casenumber']['und'][0]['value'].')' .$form_state['values']['field_mnc']['und'][0]['value'] .' ('.$jdate.')';

		
		 
		//add the new title back to the form_state
		$form_state['values']['title'] = $title;
	}

?>
