<?php
/*
 * Copyright (c) 2017, Sohrab Monfared <sohrab.monfared@gmail.com>
 * All rights reserved.

 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *    * Redistributions of source code must retain the above copyright
 *      notice, this list of conditions and the following disclaimer.
 *    * Redistributions in binary form must reproduce the above copyright
 *      notice, this list of conditions and the following disclaimer in the
 *      documentation and/or other materials provided with the distribution.
 *    * Neither the name of the <organization> nor the
 *      names of its contributors may be used to endorse or promote products
 *      derived from this software without specific prior written permission.

 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL <COPYRIGHT HOLDER> BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

function _contact_form_array_to_xml($array, &$xml_array) {

  foreach($array as $key => $value) {

    if(is_array($value)) {

      $key = is_numeric($key) ? "item-$key" : $key;

      $subnode = $xml_array->addChild($key);

      array_to_xml($value, $subnode);

    } else {

      $key = is_numeric($key) ? "item-$key" : $key;

      $xml_array->addChild($key, $value);

    }

  }

}

function contact_form_save_to_xml_file(array $post_array, $xml_file_path=NULL){

  $contact_xml = NULL;
  $error = NULL;

  if (!$xml_file_path){
    return -1;
  }

  if (empty($post_array)){
    return -2;
  }

  $contact_xml = new SimpleXMLElement("<?xml version=\"1.0\"?><contact_form></contact_form>");

  _contact_form_array_to_xml($post_array,$contact_xml);

  if (@$contact_xml->asXML($xml_file_path)){

    return 1;

  } else {

    $error = error_get_last();

    if ($error){
      error_log("contact_form_to_xml_file(): {$error["message"]} _at_ {$error["file"]} _line_ {$error["line"]}");
    }

    return -2;
  }

}

$post_dummy = array ("name" => "John Doe", "email" => "johndoe@example.com");
contact_form_save_to_xml_file($post_dummy, "/tmp/my.xml");

