<?php

	function courtnames_views_data(){
     
		return [
			'views' => [
				'courtnames_area' => [
					'title' => t('My Custom Area'),
					'help' => t('Adds a custom area handle.'),
					'area' => [
						'handler' => 'CourtnamesHandler',
					]
				]

			]
		];

	}