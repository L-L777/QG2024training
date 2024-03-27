let showAdd=function(){
    let show = document.querySelector('.show')
    let addBox=document.querySelector('.addBox')
    let addBtn=document.querySelector('.addBtn')
    addBtn.addEventListener('click',function(){
        show.style.display = 'flex';
        addBox.style.display = 'flex';
    })
}