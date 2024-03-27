let deleteNote=function(){
    let allNote=document.querySelector('.allNote')
    let deleteBtn=allNote.querySelectorAll('.delete')
    for(let i=0;i<deleteBtn.length;i++){
        deleteBtn[i].addEventListener('click',function(){
            let note=deleteBtn[i].parentNode.parentNode;
            allNote.removeChild(note);
        })
    }
}