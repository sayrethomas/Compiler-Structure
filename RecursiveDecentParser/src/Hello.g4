grammar Hello;
r :  num
	| nums
	| r '+' r
	| r '-' r
	| r '*' r
	| r '/' r;
num : '0'|'1'|'2'|'3'|'4'|'5'|'6'|'7'|'8'|'9';
nums : num+;
WS : [ \t\r\n]+ -> skip;
