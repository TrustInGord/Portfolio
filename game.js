let grid = [];
let targetWord = '';
let currentHint = '';
let startTime = 0;
let timer;

const wordData = [
    {word: 'QUIZ', hint: 'Test or exam'},
    {word: 'LYNX', hint: 'Wild cat with tufted ears'},
    {word: 'WAVY', hint: 'Having waves or curves'},
    {word: 'FOXY', hint: 'Cunning or attractive'},
    {word: 'JUMP', hint: 'Leap or bound'},
    {word: 'HAZY', hint: 'Misty or unclear'},
    {word: 'BUCK', hint: 'Male deer or dollar'},
    {word: 'GYMS', hint: 'Exercise facilities'},
    {word: 'ZINC', hint: 'Metallic element'},
    {word: 'WOMB', hint: 'Where babies develop'},
    {word: 'VEXT', hint: 'Annoyed (archaic)'},
    {word: 'THUD', hint: 'Dull heavy sound'},
    {word: 'SPRY', hint: 'Agile and active'},
    {word: 'QUID', hint: 'British pound slang'},
    {word: 'PLOW', hint: 'Farm tool for soil'},
    {word: 'MYTH', hint: 'Ancient story or legend'},
    {word: 'KIWI', hint: 'Flightless bird from NZ'},
    {word: 'JUNK', hint: 'Worthless items'},
    {word: 'HYMN', hint: 'Religious song'},
    {word: 'GLOW', hint: 'Emit steady light'},
    {word: 'FLUX', hint: 'Continuous change'},
    {word: 'DUNK', hint: 'Dip in liquid'},
    {word: 'CURB', hint: 'Edge of sidewalk'},
    {word: 'BOXY', hint: 'Square-shaped'},
    {word: 'AWRY', hint: 'Gone wrong'},
    {word: 'ZEST', hint: 'Enthusiasm or citrus peel'},
    {word: 'YOGI', hint: 'Yoga practitioner'},
    {word: 'WINK', hint: 'Close one eye briefly'},
    {word: 'VAMP', hint: 'Seductive woman'},
    {word: 'TURF', hint: 'Grass or territory'},
    {word: 'SPUD', hint: 'Potato slang'},
    {word: 'QUAY', hint: 'Wharf or dock'},
    {word: 'PRIM', hint: 'Proper and formal'},
    {word: 'MUSK', hint: 'Strong animal scent'},
    {word: 'KILT', hint: 'Scottish garment'},
    {word: 'JOWL', hint: 'Lower jaw or cheek'},
    {word: 'GULF', hint: 'Large bay'},
    {word: 'FUDG', hint: 'Sweet chocolate candy'},
    {word: 'DULY', hint: 'Properly or on time'},
    {word: 'CURV', hint: 'Bend or arc'},
    {word: 'BUNK', hint: 'Bed or nonsense'},
    {word: 'AWOL', hint: 'Absent without leave'},
    {word: 'ZANY', hint: 'Silly or eccentric'},
    {word: 'YURT', hint: 'Mongolian tent'},
    {word: 'WIMP', hint: 'Weak person'},
    {word: 'VOWS', hint: 'Marriage promises'},
    {word: 'TUGS', hint: 'Pulls forcefully'},
    {word: 'SWUM', hint: 'Past participle of swim'},
    {word: 'RUMP', hint: 'Hindquarters'},
    {word: 'QUIP', hint: 'Witty remark'}
];

function generateGrid() {
    const alphabet = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ';
    let letters = [];
    
    // Pick a random target word
    const selected = wordData[Math.floor(Math.random() * wordData.length)];
    targetWord = selected.word;
    currentHint = selected.hint;
    let targetLetters = [...new Set(targetWord)];
    
    // Add each letter of alphabet: once if in target word, twice if not
    for (let char of alphabet) {
        if (targetLetters.includes(char)) {
            letters.push(char);
        } else {
            letters.push(char, char);
        }
    }
    
    // Shuffle and take first 48
    for (let i = letters.length - 1; i > 0; i--) {
        const j = Math.floor(Math.random() * (i + 1));
        [letters[i], letters[j]] = [letters[j], letters[i]];
    }
    
    return letters.slice(0, 48);
}

function displayGrid() {
    const gridElement = document.getElementById('grid');
    gridElement.innerHTML = '';
    
    grid.forEach(letter => {
        const cell = document.createElement('div');
        cell.className = 'cell';
        cell.textContent = letter;
        cell.onclick = () => {
            if (cell.classList.contains('red')) {
                cell.classList.remove('red');
                cell.classList.add('green');
            } else if (cell.classList.contains('green')) {
                cell.classList.remove('green');
            } else {
                cell.classList.add('red');
            }
        };
        gridElement.appendChild(cell);
    });
}

function startTimer() {
    startTime = Date.now();
    timer = setInterval(() => {
        const elapsed = Math.floor((Date.now() - startTime) / 1000);
        document.getElementById('time').textContent = elapsed;
    }, 1000);
}

function submitGuess() {
    const guess = document.getElementById('guess').value.toUpperCase();
    const result = document.getElementById('result');
    
    if (guess === targetWord) {
        clearInterval(timer);
        const time = Math.floor((Date.now() - startTime) / 1000);
        result.innerHTML = `<span style="color: green;">Correct! Time: ${time}s</span>`;
    } else {
        result.innerHTML = `<span style="color: red;">Try again!</span>`;
    }
}

function newGame() {
    grid = generateGrid();
    displayGrid();
    document.getElementById('guess').value = '';
    document.getElementById('result').innerHTML = '';
    document.getElementById('time').textContent = '0';
    document.getElementById('secret').innerHTML = 'Hint: ' + currentHint;
    clearInterval(timer);
    startTimer();
}

function revealSecret() {
    document.getElementById('secret').innerHTML = 'Hint: ' + currentHint + '<br>Secret word: ' + targetWord;
}

function startGame() {
    document.getElementById('startBtn').style.display = 'none';
    document.getElementById('newBtn').style.display = 'inline-block';
    document.getElementById('revealBtn').style.display = 'inline-block';
    newGame();
}

function showRules() {
    const rules = 'FIND THE FOUR LETTER WORD MADE FROM LETTERS APPEAR ONLY ONCE IN THE GRID';
    const gridElement = document.getElementById('grid');
    gridElement.innerHTML = '';
    
    for (let i = 0; i < 48; i++) {
        const cell = document.createElement('div');
        cell.className = 'cell';
        const char = rules[i % rules.length];
        cell.textContent = char;
        
        const pos = i % rules.length;
        if (pos >= 0 && pos <= 3) cell.classList.add('green'); // FIND
        if (pos >= 5 && pos <= 7) cell.classList.add('red');   // THE
        
        gridElement.appendChild(cell);
    }
}

// Show rules initially
showRules();