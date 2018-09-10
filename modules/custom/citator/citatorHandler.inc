<?php

	class CitatorHandler extends views_handler_area_text{
		
		function render($empty = FALSE){
		

			$found_citations = "";       
            $node = node_load(arg(1));
            $node_id = arg(1);

			$api_url = "http://www.africanliicitator.co.za/api/read_processed_case/Uganda".$node_id."/by_node/";

			$ch = curl_init($api_url);
			curl_setopt($ch, CURLOPT_HTTPAUTH, CURLAUTH_BASIC);
			curl_setopt($ch, CURLOPT_USERPWD, "admin:Citator13.");		
			//$headers = array('Content-type: application/json', 'Authorization: Token ' .$token);
			curl_setopt($ch, CURLOPT_SSL_VERIFYPEER, false);
			curl_setopt($ch, CURLOPT_RETURNTRANSFER, true);
			curl_setopt($ch, CURLOPT_URL,$api_url);
			//curl_setopt($ch, CURLOPT_HTTPHEADER, $headers);

			$references = json_decode(curl_exec($ch));						
			curl_close($ch); 

			//echo '<pre>';
			//print_r($references);exit;   
            			
            $citation = '<ul>';
            if(!is_null($references)){
				if(arg(1) == $references->node){
	                
	            	foreach($references->citations as $citations){
	                	$found_id = str_replace("Uganda","",$citations->processed_case);
	                    $cit_url = $this->get_url_alias($found_id);                  
	                    $url_alias = (isset($_SERVER['HTTPS']) ? "https" : "http") . "://$_SERVER[HTTP_HOST]/".$cit_url;    
	                    $citation .= t('<li><a href="@url">'.$citations->text.'</a></li>',array('@url' => url($url_alias)));
	                }
	                $citation .= '</ul>';
	               
	            }
            }
			return $citation;
		}


		function output_results(){
			
   				
   			//$api_url = "http://www.africanliicitator.co.za/api/write_processed_case.json";
            //$api_ur = "http://www.africanliicitator.co.za/api/read_processed_case.json";
            //$api_url = "http://www.africanliicitator.co.za/api/read_processed_case/Uganda28712/by_node/";
            $api_url = "http://www.africanliicitator.co.za/api/read_processed_case/Uganda27951/by_node/";

			$ch = curl_init($api_url);
			curl_setopt($ch, CURLOPT_HTTPAUTH, CURLAUTH_BASIC);
			curl_setopt($ch, CURLOPT_USERPWD, "admin:Citator13.");		
			//$headers = array('Content-type: application/json', 'Authorization: Token ' .$token);
			curl_setopt($ch, CURLOPT_SSL_VERIFYPEER, false);
			curl_setopt($ch, CURLOPT_RETURNTRANSFER, true);
			curl_setopt($ch, CURLOPT_URL,$api_url);
			//curl_setopt($ch, CURLOPT_HTTPHEADER, $headers);

			$result = json_decode(curl_exec($ch));						
			curl_close($ch);

			return $result;
			
		}
        
        
        function get_url_alias($nid){
        	$source = 'node/'.$nid;
			$url_alias =  db_query("SELECT {alias} FROM {url_alias} WHERE {source} = :source", array(':source' => $source))->fetchField();
			return $url_alias;
		}
		
	}