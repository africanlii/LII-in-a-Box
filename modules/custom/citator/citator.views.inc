<?php

	function citator_views_data(){
     
		return [
			'views' => [
				'citator_area' => [
					'title' => t('Citations Custom Area'),
					'help' => t('Adds a custom area handle.'),
					'area' => [
						'handler' => 'CitatorHandler',
					]
				]

			]
		];

	}