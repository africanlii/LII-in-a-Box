<?php

	function legislation_promulgated_form_alter(&$form, &$form_state, $form_id) {
		if($form_id == 'legislation_node_form') { 
			//un-require the title and hide it, we will auto title the content on submit
			$form['title']['#required'] = FALSE;
			$form['title']['#type'] = 'value';
			$form['#submit'][] = 'legislation_promulgated_node_form_submit';
			 
		} 
 	}

 	function legislation_promulgated_node_form_submit(&$form, &$form_state) {
 
		//add in the current timestamp
<<<<<<< HEAD
		//$title = $form_state['input']['field_shorttitle']['und'][0]['value'];
=======
		$title = $form_state['input']['field_shorttitle']['und'][0]['value'];
>>>>>>> dc0acc079329d1688fc63536d42cf8f0b2a82da3
		 
		//add the new title back to the form_state
		//$form_state['values']['title'] = $title;
}