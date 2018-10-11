<?php

	/**
	 * Options callback for simple_content_type_checkboxes field
	 * @return - returns an indexed array as integer => string
	 */
	//function to create dropdown values of court names


	function citator_form_alter(&$form, &$form_state, $form_id) {
		if($form_id == 'citator_node_form') {
		 
			//un-require the title and hide it, we will auto title the content on submit
			$form['title']['#required'] = TRUE;
			$form['title']['#type'] = 'value';
			$form['#submit'][] = 'citator_node_form_submit';
		 
		} 
	 	
	 	
	}

	/**
	* Custom submit handler for observation nodes to alter the title
	*/
	function citator_node_form_submit(&$form, &$form_state) {
	 
		//$title = '';	
		//$form_state['values']['title'] = $title;
	}

?>
