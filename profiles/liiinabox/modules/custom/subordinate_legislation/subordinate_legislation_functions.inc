<?php

	function subordinate_legislation_form_alter(&$form, &$form_state, $form_id) {
		if($form_id == 'subordinate_legislation_node_form') { 
			//un-require the title and hide it, we will auto title the content on submit
			$form['title']['#required'] = FALSE;
			//$form['title']['#type'] = 'value';
			$form['#submit'][] = 'subordinate_legislation_node_form_submit';
			 
		} 
 	}

 	function subordinate_legislation_node_form_submit(&$form, &$form_state) {
 
		//add in the current timestamp
		//$title = $form_state['input']['field_shorttitle']['und'][0]['value'];
		 
		//add the new title back to the form_state
		//$form_state['values']['title'] = $title;
}