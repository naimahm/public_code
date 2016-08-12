/* UITLITY FUNCTIONS */
function numericalLettersMap(letter){
	return (letter.toLowerCase().charCodeAt(0)-96)%9 ? (letter.toLowerCase().charCodeAt(0)-96)%9 : 9;
}

function digitSum(n){
	if(n == 11|| n == 22 || n == 33) return n //magic numbers
	if(n/10 < 1) return n%10;
	return n%10 + digitSum(Math.floor(n/10));
}

function digitSumNoMasters(n){
	return (n/10 < 1) ? n%10 : n%10 + digitSumNoMasters(Math.floor(n/10)); //one line to sum digits
}

function singleDigitReduce(n){
	while(n > 9){
		let sum = 0;
		sum = digitSum(n);
		n = sum;
	}
	return n;
}

function sanitizeName(fullName, type){
	var lettersOnly = fullName.toLowerCase().split("").filter(l => l.match(/[a-z]/));
	if(type == "vowels")
		return lettersOnly.filter(l => l.match(/[a|e|i|o|u]/));
	if(type == "consonants")
		return lettersOnly.filter(l => !l.match(/[a|e|i|o|u]/));
	return lettersOnly;
}

/* NUMEROLOGY FUNCTIONS */

function getLifePathNumber(birthString){
	return singleDigitReduce(birthString.split('/').reduce((acc,cur) => acc += singleDigitReduce(Number(cur)), 0));
}

function getExpressionNumber(fullName){
	return singleDigitReduce(sanitizeName(fullName).reduce((acc,cur) => acc += numericalLettersMap(cur), 0));
}
 
function getHeartsDesireNumber(fullName){
	return singleDigitReduce(sanitizeName(fullName, "vowels").reduce((acc,cur) => acc += numericalLettersMap(cur), 0));
}

function getExpressionNumber(fullName){
	return singleDigitReduce(sanitizeName(fullName, "consonants").reduce((acc,cur) => acc += numericalLettersMap(cur), 0));
}

function getCornerstoneNumber(fullName){
	return singleDigitReduce(numericalLettersMap(sanitizeName(fullName).toLowerCase()[0]));
}

function getCapstoneNumber(fullName){
	return singleDigitReduce(numericalLettersMap(sanitizeName(fullName).toLowerCase()[sanitizeName(fullName).length - 1]));
}

function getFirstVowelNumber(fullName){
	return singleDigitReduce(numericalLettersMap(sanitizeName(fullName, "vowels")[0]));
}

function getExpressionNumber(fullName){
	return sanitizeName(fullName).reduce((acc,cur) => {acc[numericalLettersMap(cur)] = ((acc[numericalLettersMap(cur)] + 1) || 0); return acc}, {});
}

 