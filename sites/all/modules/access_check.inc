<?php

	function _checkAccess(){
  global $user;
  if ($user->uid) { // user is logged in
    return TRUE;
  } // Anonymous
  return FALSE;
}
?>
