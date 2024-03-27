let reserve = function () {
    let hidden = document.querySelectorAll('.hidden')
    let note = {};
    let allNote = [];
    for (let i = 0; i < hidden.length; i++) {
        let note = {};
        let title = hidden[i].querySelector('h1').textContent
        let content = hidden[i].querySelector('p').textContent
        note.index = i
        note.title = title
        note.content = content
        allNote.push(note);
    }

    localStorage.setItem('allnote', JSON.stringify(allNote))
    // console.log(allNote);
}
