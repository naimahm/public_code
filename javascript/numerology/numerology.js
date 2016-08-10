//TODO: breakdown sum if its more than a signle digit until you're left with one digit
function digitSum(n){
	if(n == 11|| n == 22 || n == 33) return n //magic numbers
	if(n/10 < 1) return n%10;
	return n%10 + digitSum(Math.floor(n/10));
}
//digitSum = (n) => (n/10 < 1) ? n%10 : n%10 + digitReducer(Math.floor(n/10)); one line to sum digits


function getLifePath(birthString){
	var birthArray = birthString.split('/');
	birthArray.map(d=> digitSum(Number(d)));
}
