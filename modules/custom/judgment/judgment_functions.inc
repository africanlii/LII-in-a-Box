<?php

	/**
	 * Options callback for simple_content_type_checkboxes field
	 * @return - returns an indexed array as integer => string
	 */
	//function to create dropdown values of court names
	function _judgment_options_list(){

		$bundle = 'courtnamesadd';  		
		
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

		$jdate = $form_state['input']['field_jdate']['und'][0]['value']['date'];
		//$year = $mnc_year = date('Y',strtotime($form_state['input']['field_jdate']['und'][0]['value']['date']));
        $year = $mnc_year = date('Y',strtotime($form_state['input']['field_jdate']['und'][0]['value']['year']));
        $courtname = $form_state['input']['field_issuingcourt_select']['und'];

		$query = db_query("SELECT MAX(field_jno_value) as max_jno, field_issuingcourt_select_value, field_mnc_value
        	FROM  field_data_field_jno as jno, field_data_field_issuingcourt_select court, field_data_field_mnc as mnc 
        	WHERE mnc.field_mnc_value LIKE '%$year%'
        	AND mnc.entity_id = jno.entity_id
            AND court.field_issuingcourt_select_value = '$courtname'
            AND court.entity_id = jno.entity_id ")->fetchCol();
		
		$max_jno = $query[0];



		if($form_state['input']['field_jno']['und'][0]['value'] == ''){
		
			$form_state['values']['field_jno']['und'][0]['value'] = $max_jno+1;
			//echo $form_state['input']['field_jno']['und'][0]['value'] = $max_jno+1;exit;
		}

		$country_code = strtoupper(variable_get('site_default_country'));

		//Automating MNC code
		//$mnc_year = date('Y',strtotime($form_state['input']['field_jdate']['und'][0]['value']['date']));
        //Changed the date format is separated into blocks: day-month-year
        $mnc_year = date('Y',strtotime($form_state['input']['field_jdate']['und'][0]['value']['year']));
		$mnc_jno = $form_state['values']['field_jno']['und'][0]['value'];		
		

		$court_name = $form_state['input']['field_issuingcourt_select']['und'];
		$bundle = 'courtnamesadd';
  		
		/*$result = db_query("SELECT mnc.field_courtmnc_value FROM {field_data_field_courtmnc} mnc 
  			LEFT JOIN {node} nd
  			ON nd.nid = mnc.entity_id
  			AND nd.title = '$court_name'"); */
        
		$result = db_query("SELECT mnc.field_courtmnc_value,mnc.entity_id, nd.nid, nd.title FROM field_data_field_courtmnc AS mnc, node AS nd 
  			WHERE nd.nid = mnc.entity_id
  			AND nd.title = '$court_name' ");

  		$record = $result->fetchObject();
         
		//var_dump($record->field_courtmnc_value);exit;

  		$mncval = "[".$mnc_year."] ".$record->field_courtmnc_value." ".$mnc_jno;

		if($form_state['input']['field_mnc']['und'][0]['value'] == ''){
			$form_state['values']['field_mnc']['und'][0]['value'] = $mncval;
		}



		$title = $form_state['input']['field_casename']['und'][0]['value'] .' ('.$form_state['input']['field_casenumber']['und'][0]['value'].')' .$form_state['values']['field_mnc']['und'][0]['value'] .' ('.$jdate.')';

		
		 
		//add the new title back to the form_state
		$form_state['values']['title'] = $title;
	}

?>
