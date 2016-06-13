<?php

/**
 * @file
 * The PHP page that serves all page requests on a Drupal installation.
 *
 * The routines here dispatch control to the appropriate handler, which then
 * prints the appropriate page.
 *
 * All Drupal code is released under the GNU General Public License.
 * See COPYRIGHT.txt and LICENSE.txt.
 */

/**
 * Root directory of Drupal installation.
 */
define('DRUPAL_ROOT', getcwd());

require_once DRUPAL_ROOT . '/includes/bootstrap.inc';
drupal_bootstrap(DRUPAL_BOOTSTRAP_FULL);
menu_execute_active_handler();

if(!module_exists('judgment')){   
      $modules = array('judgment','consolidated_legislation','subordinate_legislation','legislation_promulgated','journal','bills','gazette','other'); // Array of module names
      $enable_dependencies = TRUE;
      module_enable($modules, $enable_dependencies);
}
