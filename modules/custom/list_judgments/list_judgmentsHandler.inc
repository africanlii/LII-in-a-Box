<?php

	class list_judgmentsHandler extends views_handler_area_text{
		
		function render($empty = FALSE){
					
			return $this->output_results();
		}


		function output_results(){
			
   			$path = current_path();
   			//return $this->page_courtnames($path);
   			$path_ar = explode('/',$path);
            
            //echo count($path_ar);exit;
		    if(count($path_ar) == 3){
		        return $this->page_list_judgments($path);
		    }
		    else{
		        return $this->judgments_begin_with($path);
		    }
		}

		/**
		*  Page callback mapped to the url /courtnames
		*
		* @return array
		*/
		function page_list_judgments($current_path) {
		  $content = array();

		  //Code added to fix url paths
		  //$path_ar = explode('/',current_path());
		  $urlpath = $current_path;
		  $path_ar = explode('/',$current_path);
		  $passedcourtname = $path_ar[2];
		  $courtname = str_replace('-',' ',$passedcourtname);
          $courtname = ucwords($courtname);
		  drupal_set_title(ucwords($courtname).' decisions');

		  //print_r($path_ar);
		  
		  //echo count($path_ar);

		  $type = 'judgment';
		  $mnc_code = 'scza';
		  $result = db_query("SELECT * FROM {node} WHERE type = :type",array(':type' => $type,));

		  $result2 = db_query("SELECT jdate.field_jdate_value FROM {field_revision_field_issuingcourt_select} issuingcourt INNER JOIN {field_data_field_jdate} jdate
		                         ON issuingcourt.entity_id = jdate.entity_id 
		                         WHERE issuingcourt.field_issuingcourt_select_value = '$courtname' ");  


		  $date_ar = array();
		  $date_year = array();
		  foreach($result2 as $dt){

		    $date_ar[] = date('j F Y',strtotime($dt->field_jdate_value)).'<br/>';
		    $yearval = date('Y',strtotime($dt->field_jdate_value));
		    if(!in_array($yearval,$date_year)){
		      $date_year[] = $yearval;
		    }
		    
		  }
		  $num = count($date_ar);



		  //query to extract the first letter of the judgment
		  $sqlresult = db_query("SELECT SUBSTRING(nd.title,1,1) AS letter,nd.title, issuingcourt.field_issuingcourt_select_value FROM {node} nd INNER JOIN { field_data_field_issuingcourt_select} issuingcourt ON 
		  nd.nid = issuingcourt.entity_id WHERE issuingcourt.field_issuingcourt_select_value LIKE '%$courtname%' GROUP BY nd.title ");
		  
		  $alpha = array();

		  foreach($sqlresult as $letters){
		    $alpha[$letters->letter] = $letters->title;
		  }

		  $query2=db_query("SELECT DATE_FORMAT(jdate.field_jdate_value,'%d %M %Y') FROM {field_revision_field_issuingcourt_select} issuingcourt INNER JOIN {field_data_field_jdate} jdate
		                         ON issuingcourt.entity_id = jdate.entity_id 
		                         WHERE issuingcourt.field_issuingcourt_select_value LIKE '%$courtname%' ORDER BY jdate.field_jdate_value  ")->fetchCol();

		  if($num > 0){
		      $ind = count($query2)-1;
		      $created = $query2[$ind];
		          
		      $titles = '';
		      foreach ($result as $row) {
		        $titles .= $row->title.'<br />';
		      }

		      //$content['titles'] = $titles;
		      $lists = '<p>Most recent decision: '. $created .'<br/>';
		      $lists .= 'Number of decisions: '. $num .'<br/>';
		      $lists .= 'Decisions beginning with:</p>';

		      $word = '<p></p>';
		      foreach(range('A','Z') as $i) {
		    
		        $word .= (array_key_exists ("$i", $alpha)) ? t('<a href="@url">'.$i.'</a>', array('@url' => url($urlpath.'/'.strtolower($i)))) : "$i";
		        $word .= ($i != 'Z') ? ' | ':'';
		       
		      }


		      $years_cont = '<p></p><p>Decisions for the years:</p>';

		      sort($date_year);
		      $years_range = '<p></p>';
		      foreach($date_year as $year) {
		        //$years_range .= t('<a href="@url">'.$year.'</a>|', array('@url' => url('courtdecisions/'.$passedcourtname.'/'.$year)));
		        $years_range .= t('<a href="@url">'.$year.'</a> | ', array('@url' => url($urlpath.'/'. $year)));
		      }

		      $content['content'] = array(
		        '#markup'=>t($lists.$word.$years_cont.$years_range),
		      );
		      $content2 = t($lists.$word.$years_cont.$years_range);
		  }
		  else{
		    //$content['content'] = array(
		    //'#markup'=>t("<strong>There are currently no judgments loaded for this court</strong>"),);
		     $content2 = t("<strong>There are currently no judgments loaded for this court</strong>");
                   
		  }
		  
		  return $content2;
		}
	


	function judgments_begin_with($current_path) {
 

	    //Code added for fixing the url-path
	    //$path_ar = explode('/',current_path());
	    $path_ar = explode('/',$current_path);
	    //print_r($path_ar);exit;
	    $passedcourtname = $path_ar[2];
	    $letter = strtoupper($path_ar[3]);
	    $courtname = str_replace('-',' ',$passedcourtname);
	    $courtname = ucwords($courtname);

	    if(strlen($letter) == 1){

	        drupal_set_title($courtname.': Decisions beginning with'.' '.$letter);

	        $queryres=db_query("SELECT nd.title, ualias.alias, issuingcourt.field_issuingcourt_select_value 
	        FROM {node} nd INNER JOIN {field_data_field_issuingcourt_select} issuingcourt ON 
	        nd.nid = issuingcourt.entity_id
	        INNER JOIN {url_alias} ualias ON
	        ualias.source = CONCAT('node/',nd.nid) 
	        AND nd.title LIKE '$letter%'
	        AND issuingcourt.field_issuingcourt_select_value LIKE '%$courtname%'
	        AND nd.type = 'judgment' GROUP BY  nd.title ");

	        //$data = '<p><strong>type:</strong> judgment';
	        //$data .= '<p><strong>database:</strong> '.$courtname;
	        //$data .= '<p><strong>alpha:</strong> '.$letter;
	        $data = "<p>";
	        foreach($queryres as $result){
	          $content_title = $result->title;
	          $content_src = $result->alias;
	          //$data .="<li><a href='$content_src'>$content_title</a></li>"; 
	          $data .= t('<ul><li><a href="@url">'.$content_title.'</a></li></ul>', array('@url' => url($content_src)));
	        }
	        $data .= "</p>";

	        $content['content'] = array(
	          '#markup'=>t($data),
	        );
	        $content_out= t($data);
	        
	    }
	    else {
	      $passedcourtname = $path_ar[2];
	      $year = strtoupper($path_ar[3]);
	      $courtname = str_replace('-',' ',$passedcourtname);
	      $courtname = ucwords($courtname);
	      //print_r(current_path());exit;
	      drupal_set_title($courtname.': Decisions in'.' '.$year);
	 
	      //$metadata = '<p><strong>type:</strong>judgment';
	      //$metadata .= '<p><strong>database:</strong>'.$courtname;
	      //$metadata .= '<p><strong>year:</strong>'.$year;
	      $metadata = '<p>';
	      $result = db_query("SELECT jdate.field_jdate_value,n.title,ualias.alias FROM {field_revision_field_issuingcourt_select} issuingcourt     
	        INNER JOIN {field_data_field_jdate} jdate
	        ON issuingcourt.entity_id = jdate.entity_id 
	        INNER JOIN {node} n 
	        ON n.nid = jdate.entity_id
	        AND n.type = 'judgment'
	        INNER JOIN {url_alias} ualias
	        ON CONCAT('node/',n.nid) = ualias.source
	        WHERE issuingcourt.field_issuingcourt_select_value LIKE '%$courtname%' GROUP BY jdate.field_jdate_value, n.title ");

	      $date_month = array();
	      

	      $date_ar = array();  
	      $months = '<p></p>';
	      $titles = '<p>';  
	      $prev_month = "";
	     
	      foreach($result as $res){
	        $yearjudg = date('Y',strtotime($res->field_jdate_value));    
	        $content_month = date('F Y',strtotime($res->field_jdate_value));
	        $monthjudg = date('F',strtotime($res->field_jdate_value));  
	        $alias = $res->alias;

	        //echo $alias.'<br/>';
	        if($yearjudg == $year){     
	          if($prev_month != $content_month){
	            $titles .= '<strong>'.$content_month.'</strong>'.'<br/>';
	          }      
	          //$titles .= '<li>'."<a href='$alias'>".$res->title.'</a></li>';
	          $titles .= t('<ul><li><a href="@url">'.$res->title.'</a></li></ul>', array('@url' => url($alias)));
	          $prev_month = $content_month;
	        }            
	      }// End of for loop
	      
	      $titles .= '</p>';
	      
	      $content['content'] = array(
	        '#markup'=>t($metadata.$months.$titles),
	      );

	      $content_out = t($metadata.$months.$titles);

	  }
	  return $content_out;
	}

}
