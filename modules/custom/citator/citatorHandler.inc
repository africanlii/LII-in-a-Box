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
		
            $citation_results = '<h2 class="block-title">CASES CONSIDERED</h2><ul>';
            $citation_links = '';
            if(!is_null($references)){
            	if(isset($references->node)){            		
					if(arg(1) == $references->node){
						
					   	foreach($references->citations as $citations){
		                	$found_id = str_replace("Uganda","",$citations->link_url);
		                    $cit_url = $this->get_url_alias($found_id);                  
		                    $url_alias = (isset($_SERVER['HTTPS']) ? "https" : "http") . "://$_SERVER[HTTP_HOST]/".$cit_url;
	                        if($cit_url != ''){
		                    	$citation_links .= t('<li><a href="@url">'.$citations->text.'</a></li>',array('@url' => url($url_alias)));
	                        }
		                }
		                //$citation .= '</ul>';
		               $citation_results .= $citation_links.'</ul>';
		            }		            
	        	}
            }

            //echo $citation_links;exit;
            //echo strlen($citation);exit;
            //Checking if the string with links is empty returns length 54, if empty hide block title           
            if($citation_links == ''){
		       	$citation_results = '';
		       	
		    }
			return $citation_results;
		}
	
        
        function get_url_alias($nid){
        	$source = 'node/'.$nid;
			$url_alias =  db_query("SELECT {alias} FROM {url_alias} WHERE {source} = :source", array(':source' => $source))->fetchField();
			return $url_alias;
		}
}