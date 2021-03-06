<?php

/*
 * Good.
 */
$good = array();

$good = array( 1, 2, 3 );
$good = [ 'a', 'b', 'c' ];

$good = array(
	1,
	2,
	3,
);
$good = [
	'a',
	'b',
	'c',
];

$good = array(
	1 => 'value',
	2 => array( 1 ),
	3 => apply_filters( 'filter', $input, $var ), /* Comment. */
);
$good = [
	'a' => 'value',          // Comment - the extra spacing is fine, might be for alignment with other comments.
	'b' => array( 1 ),
	'c' => apply_filters( 'filter', $input, $var ),
];

// OK: that this should be a multi-line array is not the concern of this sniff.
$good = array( 1 => 'a', 2 => 'b', 3 => 'c' );
$good = [ 'a' => 1, 'b' => 2, 'c' => 3 ];

$good = array( 1, 2, // OK: that each item should be on its own line or single line array is not the concern of this sniff.
	3, ); // OK: that the brace should be on another line is not the concern of this sniff.

/*
 * Bad.
 */
// Spacing before comma.
$bad = array( 1 , 2         , 3 ); // Bad x2.
$bad = [ 'a' , 'b'    , 'c' ]; // Bad x2.

// Spacing after comma.
$bad = array( 1,2,    3 ); // Bad x2.
$bad = [ 'a','b',    'c' ]; // Bad x2.

// Comma after last.
$bad = array( 1, 2, 3, );
$bad = [ 'a', 'b', 'c', ];

// Spacing before comma.
$bad = array(
	1 => 'value'  ,
	2 => array( 1 ) ,
	3 => apply_filters( 'filter', $input, $var )       , /* Comment. */
);
$bad = [
	'a' => 'value'  ,          // Comment - the extra spacing is fine, might be for alignment with other comments.
	'b' => array( 1 )


	 ,
	'c' => apply_filters( 'filter', $input, $var )     ,
];

// NO spacing after comma.
$bad = array(
	3 => apply_filters( 'filter', $input, $var ),/* Comment. */
);
$bad = [
	'a' => 'value',// Comment.
];

// NO comma after last.
$bad = array(
	1 => 'value',
	2 => array( 1 ),
	3 => apply_filters( 'filter', $input, $var )/* Comment. */
);
$bad = [
	'a' => 'value',          // Comment - the extra spacing is fine, might be for alignment with other comments.
	'b' => array( 1 ),
	'c' => apply_filters( 'filter', $input, $var )
];

$bad = array( 1 => 'a' ,    2 => 'b',3 => 'c', );
$bad = [ 'a' => 1   ,   'b' => 2,'c' => 3, ];

$bad = array( 1  ,    2,
	3 );

// Combining a lot of errors in a nested array.
$bad = array(
	1 => 'value' ,
	2 => [
		'a' => 'value'     ,// Comment - the extra spacing is fine, might be for alignment with other comments.
		'b' => array(
			1
		),
		'c' => apply_filters( 'filter', $input, $var )
	],
	3 => apply_filters( 'filter', $input, $var )/* Comment. */
);

// Alternative array style.
$bad = array(
          1 => 'value'
        , 2 => array( 1 )
        , 3 => apply_filters( 'filter', $input, $var )/* Comment. */
);
$bad = [
	  'a' => 'value'          // Comment - the extra spacing is fine, might be for alignment with other comments.
	, 'b' => array( 1 )
	, 'c' => apply_filters( 'filter', $input, $var )
];
$bad = [
	 'a' => 'value'          // Comment - the extra spacing is fine, might be for alignment with other comments.
	,'b' => array( 1 )
	,'c' => apply_filters( 'filter', $input, $var ),
];

$bad = array(
         'first',
         'second'
         //'third',
        );

$bad = array(
 'key3' => function($bar) {
    return $bar;
 }
);

// Issue #998.
$a = array(
	'foo' => bar( 1, 29 ));

// Issue #986.
get_current_screen()->add_help_tab( array(
		'id'		=> <<<EOD
Here comes some text.
EOD
,
) );

get_current_screen()->add_help_tab( array(
'id'		=> <<<EOD
Here comes some text.
EOD
. '</hr>',
) );
