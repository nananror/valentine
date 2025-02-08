<!DOCTYPE html>
<html lang="id">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Valentine Game</title>
    <style>
        body { font-family: Arial, sans-serif; text-align: center; margin: 50px; }
        .question-container { margin-top: 20px; }
        input { margin-top: 10px; padding: 5px; }
        button { margin-top: 10px; padding: 10px; cursor: pointer; }
    </style>
</head>
<body>
    <h1>Selamat Datang di Valentine Game!</h1>
    <p>Masukkan namamu:</p>
    <input type="text" id="nameInput">
    <button onclick="startGame()">Mulai</button>
    
    <div id="game" class="question-container" style="display:none;">
        <p id="questionText"></p>
        <input type="text" id="answerInput">
        <button onclick="checkAnswer()">Submit</button>
        <p id="feedback"></p>
    </div>
    
    <script>
        const questions = [
            { question: "Apa warna mawar yang sering dikaitkan dengan cinta?", answer: "Merah" },
            { question: "Tanggal berapa Valentine dirayakan?", answer: "14 Februari" },
            { question: "Apa simbol utama dari hari Valentine?", answer: "Hati" }
        ];
        
        let currentQuestion = 0;
        let playerName = "";

        function startGame() {
            playerName = document.getElementById("nameInput").value;
            if (playerName.trim() === "") {
                alert("Masukkan namamu dulu!");
                return;
            }
            document.getElementById("game").style.display = "block";
            document.getElementById("questionText").innerText = questions[currentQuestion].question;
        }

        function checkAnswer() {
            let userAnswer = document.getElementById("answerInput").value;
            let feedback = document.getElementById("feedback");
            
            if (userAnswer.trim().toLowerCase() === questions[currentQuestion].answer.toLowerCase()) {
                feedback.innerText = "Benar! Kamu romantis!";
            } else {
                feedback.innerText = "Salah! Coba lagi!";
                return;
            }
            
            currentQuestion++;
            if (currentQuestion < questions.length) {
                document.getElementById("questionText").innerText = questions[currentQuestion].question;
                document.getElementById("answerInput").value = "";
                feedback.innerText = "";
            } else {
                feedback.innerText = `Terima kasih telah bermain, ${playerName}! Selamat Hari Valentine!`;
            }
        }
    </script>
</body>
</html>

