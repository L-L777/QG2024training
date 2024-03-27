let change=function(){
    let show=document.querySelector('.show')
    
    let showBox=show.querySelector('.showBox')
    let keep = showBox.querySelector('.keep')
    let allNote = document.querySelector('.allNote')
    let changeBtn=allNote.querySelectorAll('.change')
    let titleBox = showBox.querySelector('.title_cont')
    // console.log(addBox.querySelector('.addtitle'));
    let contentBox = showBox.querySelector('.re_event')
    for (let i = 0; i < changeBtn.length; i++) {
        changeBtn[i].addEventListener('click', function () {
            show.style.display='flex';
            showBox.style.display='flex';
            let noteFun = changeBtn[i].parentNode
            let head = noteFun.previousElementSibling
            let hidden = noteFun.nextElementSibling
            let titleBox = showBox.querySelector('.title_cont')
            // console.log(addBox.querySelector('.addtitle'));
            let contentBox = showBox.querySelector('.re_event')
            titleBox.value=hidden.querySelector('h1').textContent
            contentBox.value=hidden.querySelector('p').textContent
            console.log(head);
            keep.addEventListener('click', function () {
               
                let title = titleBox.value
                let content = contentBox.value
// console.log(title);
                head.querySelector('h1').innerText = title
                hidden.querySelector('h1').innerText = title
                hidden.querySelector('p').innerText = content
                alert("保存成功")
            })
        })
       
    }
   
}
