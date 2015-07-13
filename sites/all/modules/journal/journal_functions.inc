<?php
	

		function _journaltitles_options_list(){

			$bundle = 'journaltitle';
	  		$mnc_code = 'scza';
	  		
			$result = db_query("SELECT title FROM {node} WHERE type = :bundle",array(':bundle' => $bundle,));
			$options = array();

			foreach($result as $option){
				$options[$option->title] = $option->title;
			}
				
			return $options;
		}
?>