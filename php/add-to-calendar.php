<?php
if(isset($_GET['description']) && isset($_GET['title']) && isset($_GET['start_time']) && isset($_GET['end_time']) && isset($_GET['location']) && isset($_GET['type'])){
	if(!isset($_GET['timezone'])) date_default_timezone_set('America/Los_Angeles');
	$description =$_GET['description'];
	$title = $_GET['title'];
	$start_time = strtotime($_GET['start_time']);
	$end_time = strtotime($_GET['end_time']); 
	$start_time = strtotime($_GET['start_time']);
	$end_time = strtotime($_GET['end_time']); 
	$location = $_GET['location'];
	$type = $_GET['type'];
	$formatted_description = preg_replace("/ /", "+", $description);//spaces are '+' returns are '%0A'
	$formatted_description = preg_replace("/\n/", "%0A", $formatted_description);//spaces are '+' returns are '%0A'
	$formatted_title = preg_replace("/ /", "+", $title);//spaces are '+' returns are '%0A'
	$formatted_title = preg_replace("/\n/", "%0A", $formatted_title);//spaces are '+' returns are '%0A'
	$ical_formatted_start_time = date('Ymd\THis', $start_time);
	$ical_formatted_end_time = date('Ymd\THis', $end_time);
	$ical_formatted_current_time = date('Ymd\THis');
	$tz_formatted_start_time = $ical_formatted_start_time."Z";
	$tz_formatted_end_time = $ical_formatted_end_time."Z";

	//yahoo
	$yahoo = 'http://calendar.yahoo.com/?view=d&v=60&type=20';
	$yahoo_params = array("st" => $tz_formatted_start_time, "in_loc" => $location,"title" =>$title, "details" => $description);
	$yahoo .= "&".http_build_query($yahoo_params);

	//google
	$google = 'https://calendar.google.com/calendar/render?action=TEMPLATE';
	$google .= '&dates='.$tz_formatted_start_time.'/'.$tz_formatted_end_time;
	$google .= '&location='.$location;
	$google .= '&text='.$formatted_title;
	$google .= '&details='.$formatted_description;

	//iCal/Outlook
	$iCal = 'BEGIN:VCALENDAR'.PHP_EOL;
	$iCal .= 'VERSION:2.0'.PHP_EOL;
	$iCal .= 'PRODID:OPSWAT.com'.PHP_EOL;
	$iCal .= 'BEGIN:VEVENT'.PHP_EOL;
	$iCal .= 'UID:5671cc3c267bc'.PHP_EOL;
	$iCal .= 'DTSTAMP;TZID="Pacific Standard Time":'.$ical_formatted_current_time; //currenttime
	$iCal .= 'DTSTART;TZID="Pacific Standard Time":'.$ical_formatted_start_time.PHP_EOL;
	$iCal .= 'SEQUENCE:0'.PHP_EOL;
	$iCal .= 'TRANSP:OPAQUE'.PHP_EOL;
	$iCal .= 'DTEND;TZID=UTC:'.$ical_formatted_end_time.PHP_EOL;
	$iCal .= 'LOCATION:'.$location.PHP_EOL;
	$iCal .= 'SUMMARY:'.$title.PHP_EOL;
	$iCal .= 'DESCRIPTION:'.$description.PHP_EOL;
	$iCal .= 'END:VEVENT'.PHP_EOL;
	$iCal .= 'END:VCALENDAR'.PHP_EOL;

	if($type == "Outlook" || $type == "iCal"){
		$output = $iCal;
		$file_url = preg_replace("/[^a-z0-9\._-]+/i", "-", $title).".ics";
		header('Content-Type: application/octet-stream');
		header("Content-Transfer-Encoding: Binary"); 
		header("Content-disposition: attachment; filename=\"" . basename($file_url) . "\"");
		//readfile($file_url); 
	}else if ($type == "Yahoo"){
		header('Content-Type: text/plain');
		$output = $yahoo;
	}else if ($type == "Google"){
		header('Content-Type: text/plain');
		$output = $google;
	}
	echo $output;
}else{
	$necessary_values = array('description', 'title', 'start_time', 'end_time', 'location', 'type');
	$missing = "Missing ";
	foreach($necessary_values as $value){
		if(!isset($_GET[$value]))
			$missing .= $value.", ";
	}
	if($missing != "Missing ")
		echo $missing;
}
?>