document.addEventListener('DOMContentLoaded', function() {
    var contactForm = document.getElementById('contactForm');
    if(contactForm){
        contactForm.addEventListener('submit', function(e){
            e.preventDefault();
            var name = document.getElementById('name').value.trim();
            var email = document.getElementById('email').value.trim();
            var msg = document.getElementById('message').value.trim();
            var formMsg = document.getElementById('formMsg');

            if(name.length < 2){
                formMsg.textContent = 'Enter your name please.';
                formMsg.style.color = 'red';
                return;
            }
            if(email.length < 5 || email.indexOf('@')<1){
                formMsg.textContent = 'Invalid email address!';
                formMsg.style.color = 'red';
                return;
            }
            if(msg.length < 5){
                formMsg.textContent = 'Please write a longer message.';
                formMsg.style.color = 'red';
                return;
            }
            formMsg.textContent = 'Thanks! Your message was received.';
            formMsg.style.color = 'green';
            contactForm.reset();
        });
    }
});