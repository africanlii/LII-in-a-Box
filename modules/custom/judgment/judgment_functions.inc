<?php

	/**
	 * Options callback for simple_content_type_checkboxes field
	 * @return - returns an indexed array as integer => string
	 */
	//function to create dropdown values of court names
	function _judgment_options_list(){

		$bundle = 'courtnamesadd';
  		$mnc_code = 'scza';
  
		$result = db_query("SELECT title FROM {node} WHERE type = :bundle",array(':bundle' => $bundle,));
		$options = array();

		foreach($result as $option){
			$options[$option->title] = $option->title;
		}
			
		return $options;
	}

	function _importance_options_list(){

		$bundle = 'importance_taxonomy';
  		$mnc_code = 'scza';
  
		$result = db_query("SELECT description FROM {taxonomy_vocabulary} WHERE machine_name = :bundle",array(':bundle' => $bundle,));
		$options = array();

		foreach($result as $option){
			$options[$option->description] = $option->description;
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
		
		$jdate = $form_state['input']['field_jdate']['und'][0]['value']['date'];
		$courtname = $jdate = $form_state['input']['field_issuingcourt_select']['und'];
		//$query = db_query("SELECT MAX(field_jno_value) as max_jno FROM field_revision_field_jno")->fetchCol();
		$query = db_query("SELECT MAX(field_jno_value) as max_jno FROM field_data_field_jno
                        INNER JOIN {field_revision_field_issuingcourt_select} issuingcourt
                        ON issuingcourt.field_issuingcourt_select_value = '$courtname'
                        AND issuingcourt.entity_id = field_data_field_jno.entity_id ")->fetchCol();

		//echo $query[0];exit;
		$max_jno = $query[0];


		if($form_state['input']['field_jno']['und'][0]['value'] == ''){
			$max_jno = $max_jno + 1;
			$form_state['values']['field_jno']['und'][0]['value'] = $max_jno;
			//echo $form_state['input']['field_jno']['und'][0]['value'] = $max_jno+1;exit;
		}

		$country_code = strtoupper(variable_get('site_default_country'));
		//echo strtoupper($country_code);exit;

		//Automating MNC code
		$mnc_year = date('Y',strtotime($form_state['input']['field_jdate']['und'][0]['value']['date']));
		$mnc_jno = $form_state['values']['field_jno']['und'][0]['value'];


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

		$title = $form_state['input']['field_casename']['und'][0]['value'] .' ('.$form_state['input']['field_casenumber']['und'][0]['value'].')' .$form_state['values']['field_mnc']['und'][0]['value'] .' ('.$jdate.')';		
		 
		//add the new title back to the form_state
		$form_state['values']['title'] = $title;
	}

?>
